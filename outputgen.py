import os
import subprocess
import threading
from PIL import Image, ImageDraw, ImageFont
from pathlib import Path
import time
from threading import Event
import argparse
from typing import Optional

class CProgramRunner:
    def __init__(
            self, 
            source_file: str, 
            output_file=None, 
            spoof_hostname=None
            ) -> None:
        self.source_file = source_file

        if output_file:
            self.output_file = output_file
        else:
            self.output_file = "program.exe" if os.name == "nt" else "./program.out"
        
        self.captured_output = []
        self.spoof_hostname = spoof_hostname

    def compile(self) -> bool: 
        print(f"Compiling {self.source_file}...")
        # Assuming gcc is set in PATH, compile the program.
        # Some C programs print prompts without a trailing newline and don't flush stdout
        # when stdout is not a TTY (it's fully buffered). To make those prompts appear
        # immediately we compile a tiny helper C file alongside the user's source that
        # sets stdout to unbuffered using setvbuf in a constructor function.
        helper_path = None
        try:
            src_dir = os.path.dirname(self.source_file) or '.'
            helper_path = os.path.join(src_dir, '__runner_unbuffer.c')
            helper_code = (
                '#include <stdio.h>\n'
                '__attribute__((constructor)) static void __set_stdout_unbuffered(void) {\n'
                '    setvbuf(stdout, NULL, _IONBF, 0);\n'
                '}\n'
            )
            # Write the helper C file next to the source so relative builds work.
            with open(helper_path, 'w', encoding='utf-8') as hf:
                hf.write(helper_code)

            # Compile including the helper file so the child's stdout is unbuffered.
            result = subprocess.run(["gcc", self.source_file, helper_path, "-o", self.output_file, "-lm"])
        finally:
            # Clean up the helper file when possible.
            try:
                if helper_path and os.path.exists(helper_path):
                    os.remove(helper_path)
            except Exception:
                pass
        if result.returncode != 0:
            raise RuntimeError("Compilation failed.")
        if self.spoof_hostname != None: 
            # If the screenshot is to be used for submission in the lab,
            # and the hostname is to be spoofed, 
            # display the compilation and execution steps as well using relative paths:
            try:
                rel_src = os.path.relpath(self.source_file).replace('\\', '/')
            except Exception:
                rel_src = self.source_file
            try:
                rel_out = os.path.relpath(self.output_file).replace('\\', '/')
                rel_cmd = os.path.join('.', rel_out).replace('\\', '/')
            except Exception:
                rel_cmd = f"./{self.output_file}"

            self.captured_output.append(f"{self.spoof_hostname}$ gcc {rel_src} -o {rel_cmd} -lm")
            self.captured_output.append(f"{self.spoof_hostname}$ {rel_cmd}\n")
        print(f"Compilation for {self.source_file} successful.")
        return True

    def run(self) -> bool:
        print("Running program...")
        process = subprocess.Popen(
            [self.output_file],
            stdin = subprocess.PIPE,
            stdout = subprocess.PIPE,
            stderr = subprocess.STDOUT,
            text = True
        )
        # Event to notify main thread that child produced output (so we don't prompt before prompt shows)
        output_started: Event = Event()

        def read_output_charwise(proc, started_event):
            # Read character by character so prompts without newline are visible immediately
            try:
                while True:
                    ch = proc.stdout.read(1)
                    if ch == '': # EOF
                        break
                    # Print as we get characters
                    print(ch, end="", flush=True)
                    # Accumulate into captured_output buffer; collect by lines when newline seen
                    if not self.captured_output: # initialize with empty string to start building
                        self.captured_output.append('')
                    if ch == '\n': # start a new line buffer
                        self.captured_output.append('')
                    else: # append char to last line
                        self.captured_output[-1] += ch
                    started_event.set()
            except Exception:
                pass

        t = threading.Thread(target=lambda: read_output_charwise(process, output_started), daemon=True)
        t.start()

        # Ensure stdin exists
        assert process.stdin is not None

        try:
            output_started.wait(timeout=2.0)

            if os.name == 'nt':
                # using msvcrt.kbhit() to poll for key presses on windows so we don't block
                import msvcrt
                line = ''
                while process.poll() is None:
                    # Poll for availability of keypress
                    if msvcrt.kbhit():
                        ch = msvcrt.getwch()
                        # Initialize captured_output buffer if needed
                        if not self.captured_output:
                            self.captured_output.append('')

                        if ch == '\r':
                            # Carriage return -> submit the line
                            print('')
                            try:
                                process.stdin.write(line + "\n")
                                process.stdin.flush()
                            except (BrokenPipeError, OSError):
                                break
                            # When Enter is pressed, start a new captured-output line
                            # so the saved transcript shows the user's input on the same line as the prompt.
                            self.captured_output.append('')
                            line = ''
                            # don't immediately block; continue so if process exits we stop
                            continue
                        elif ch in ('\x08', '\b'):
                            # Backspace handling: remove last char locally and from captured buffer
                            if line:
                                # erase locally (move back, overwrite, move back)
                                print('\b \b', end='', flush=True)
                                line = line[:-1]
                                try:
                                    if self.captured_output:
                                        self.captured_output[-1] = self.captured_output[-1][:-1]
                                except Exception:
                                    pass
                            continue
                        else:
                            # echo the character locally
                            print(ch, end='', flush=True)
                            line += ch
                            # also append the typed character to the captured output so it appears in saved transcript
                            try:
                                if not self.captured_output:
                                    self.captured_output.append('')
                                self.captured_output[-1] += ch
                            except Exception:
                                pass
                    else:
                        # No keypress yet; small sleep to avoid busy spin
                        time.sleep(0.02)
        except KeyboardInterrupt:
            process.terminate()

        # Close stdin to signal EOF to child (if still open)
        try:
            if process.stdin and not process.stdin.closed:
                process.stdin.close()
        except Exception:
            pass

        process.wait()
        # Give reader thread a moment to consume remaining output
        time.sleep(0.05)
        return True

    def save_output_image(
            self, 
            filename: str = "output.png", 
            font_name: str = "arial.ttf", 
            font_size: int = 18
            ) -> bool:
        if not self.captured_output:
            raise RuntimeError("No captured output to save.")
        
        text = "\n".join(self.captured_output)
        # Attempt to save as an image:
        try:
            font = ImageFont.truetype(font_name, font_size)
            lines = text.split("\n")

            # determine max width using font metrics
            max_width = int(max((font.getlength(line) if line else 0) for line in lines) + 40)
            total_height = len(lines) * (font_size + 5) + 40

            img = Image.new("RGB", (max_width or 100, total_height or 100), "black")
            draw = ImageDraw.Draw(img)

            y = 20
            for line in lines:
                draw.text((20, y), line, font=font, fill="green")
                y += font_size + 5

            img.save(filename)
            print(f"Saved output as '{filename}'")
        except Exception as e:
            # Fallback: write plain text file next to expected image
            txtfile = os.path.splitext(filename)[0] + ".txt"
            try:
                with open(txtfile, 'w', encoding='utf-8') as f:
                    f.write(text)
                print(f"Pillow not available or failed ({e}); saved output as '{txtfile}' instead.")
            except Exception as e2:
                print(f"Failed to save output image or text: {e2}")
        return True


class CFolderRunner:
    def __init__(
            self, 
            source_folder: str, 
            output_folder: Optional[str] = None, 
            spoof_hostname: Optional[str] = None, 
            font_name: str = "arial.ttf", 
            font_size: int = 18
            ) -> None:
        self.source_folder = source_folder
        self.output_folder = output_folder or source_folder
        self.spoof_hostname = spoof_hostname
        self.font_name = font_name
        self.font_size = font_size

    def run_all(self) -> None:
        p = Path(self.source_folder)
        if not p.exists() or not p.is_dir():
            raise RuntimeError(f"Source folder '{self.source_folder}' not found")

        self.output_folder = os.path.abspath(self.output_folder)
        os.makedirs(self.output_folder, exist_ok=True)

        c_files = sorted([f for f in p.iterdir() if f.is_file() and f.suffix.lower() == '.c'])
        for src in c_files:
            src_path = str(src)
            base = src.stem
            if os.name == 'nt':
                out_exe = os.path.join(self.output_folder, base + '.exe')
            else:
                out_exe = os.path.join(self.output_folder, base + '.out')

            print(f"\n--- Running {src.name} -> {out_exe} ---")
            runner = CProgramRunner(source_file=src_path, output_file=out_exe, spoof_hostname=self.spoof_hostname)
            try:
                runner.compile()
                runner.run()
                imgname = os.path.join(self.output_folder, base + '.png')
                runner.save_output_image(filename=imgname, font_name=self.font_name, font_size=self.font_size)
            except Exception as e:
                print(f"Error while processing {src.name}: {e}")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Compile and run C programs and capture their output as images.')
    parser.add_argument('--source-file', help='Path to a C source file to run')
    parser.add_argument('--source-folder', help='Path to a folder containing C files to run')
    parser.add_argument('--output-file', help='Output executable path (for single file)')
    parser.add_argument('--output-folder', help='Folder to place executables and images when running a folder')
    parser.add_argument('--spoof-hostname', help='Optional hostname to prefix captured commands with')
    parser.add_argument('--font-name', default='arial.ttf', help='Font name to use for saved image')
    parser.add_argument('--font-size', type=int, default=18, help='Font size to use for saved image')
    args = parser.parse_args()

    if args.source_folder:
        folder_runner = CFolderRunner(
            source_folder=args.source_folder, 
            output_folder=args.output_folder, 
            spoof_hostname=args.spoof_hostname, 
            font_name=args.font_name, 
            font_size=args.font_size
        )
        folder_runner.run_all()
    elif args.source_file:
        runner = CProgramRunner(
            source_file=args.source_file,
            output_file=args.output_file, 
            spoof_hostname=args.spoof_hostname
        )
        runner.compile()
        runner.run()
        out_img = None
        if args.output_folder:
            os.makedirs(args.output_folder, exist_ok=True)
            base = Path(args.source_file).stem
            out_img = os.path.join(args.output_folder, base + '.png')
        runner.save_output_image(
            filename=out_img or 'output.png', 
            font_name=args.font_name, 
            font_size=args.font_size
        )
    else:
        parser.print_help()