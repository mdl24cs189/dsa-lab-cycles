# DSA LAB Cycles
All lab cycle program solutions for DSA at Model Engineering College, Sem 3. 

The programs are solutions for the questions from [here.](https://dslabktu2024.blogspot.com/2025/04/lab-assignments.html) 

## Generate outputs for your program into neat png files
It is possible to generate outputs for programs in each lab cycle using outputgen.py using Python.

First install the requirements:

```pip install requirements.txt```

Then, run the output generator using
```
user@machine$ py ./outputgen.py --help

usage: outputgen.py [-h] [--source-file SOURCE_FILE] [--source-folder SOURCE_FOLDER] [--output-file OUTPUT_FILE] [--output-folder OUTPUT_FOLDER] [--spoof-hostname SPOOF_HOSTNAME] [--font-name FONT_NAME]
                    [--font-size FONT_SIZE]

Compile and run C programs and capture their output as images.

options:
  -h, --help            show this help message and exit
  --source-file SOURCE_FILE
                        Path to a C source file to run
  --source-folder SOURCE_FOLDER
                        Path to a folder containing C files to run
  --output-file OUTPUT_FILE
                        Output executable path (for single file)
  --output-folder OUTPUT_FOLDER
                        Folder to place executables and images when running a folder
  --spoof-hostname SPOOF_HOSTNAME
                        Optional hostname to prefix captured commands with
  --font-name FONT_NAME
                        Font name to use for saved image
  --font-size FONT_SIZE
                        Font size to use for saved image
```

Example: Generate output for programs in lab cycle 5 with hostname "mec@machine"
```
py ./outputgen.py --source-folder=lc5 --spoof-hostname=mec@machine
```