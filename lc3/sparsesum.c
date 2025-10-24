#include <stdio.h>
#define ROWS1 4
#define COLS1 5
#define ROWS2 4
#define COLS2 5

struct Sparse {
    int row;
    int col;
    int value;
};

struct Sparse sp1[20];
struct Sparse sp2[20];
struct Sparse sum[40];

int k1, k2, k3;

void convertToSparse(int matrix[ROWS1][COLS1], struct Sparse *sparse, int *k) {
    *k = 1;
    sparse[0].row = ROWS1;
    sparse[0].col = COLS1;
    sparse[0].value = 0;

    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            if (matrix[i][j] != 0) {
                sparse[*k].row = i;
                sparse[*k].col = j;
                sparse[*k].value = matrix[i][j];
                (*k)++;
            }
        }
    }
    sparse[0].value = *k - 1;
}

void displaySparse(struct Sparse *sparse, int k, const char *name) {
    printf("Tuple representation of %s:\n", name);
    printf("Row Col Value\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

void addSparseMatrices() {
    int i = 1, j = 1, k = 1;
    
    sum[0].row = ROWS1;
    sum[0].col = COLS1;
    
    while (i <= sp1[0].value && j <= sp2[0].value) {
        if (sp1[i].row < sp2[j].row || (sp1[i].row == sp2[j].row && sp1[i].col < sp2[j].col)) {
            sum[k] = sp1[i];
            i++;
            k++;
        }
        else if (sp1[i].row > sp2[j].row || (sp1[i].row == sp2[j].row && sp1[i].col > sp2[j].col)) {
            sum[k] = sp2[j];
            j++;
            k++;
        }
        else {
            sum[k].row = sp1[i].row;
            sum[k].col = sp1[i].col;
            sum[k].value = sp1[i].value + sp2[j].value;
            i++;
            j++;
            k++;
        }
    }
    
    while (i <= sp1[0].value) {
        sum[k] = sp1[i];
        i++;
        k++;
    }
    
    while (j <= sp2[0].value) {
        sum[k] = sp2[j];
        j++;
        k++;
    }
    
    sum[0].value = k - 1;
    k3 = k;
}

int main() {
    int matrix1[4][5] = {
        {1, 0, 0, 0, 0},
        {0, 8, 0, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 4}
    };
    
    int matrix2[4][5] = {
        {0, 0, 4, 0, 0},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 2, 0},
        {9, 0, 0, 0, 4}
    };

    convertToSparse(matrix1, sp1, &k1);
    convertToSparse(matrix2, sp2, &k2);

    displaySparse(sp1, k1, "sparse matrix 1");
    displaySparse(sp2, k2, "sparse matrix 2");

    addSparseMatrices();

    displaySparse(sum, k3, "sum of sparse matrices");

    return 0;
}