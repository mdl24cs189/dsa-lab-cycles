#include <stdio.h>
#define ROWS 4
#define COLS 5

struct Sparse
{
    int row;
    int col;
    int value;
};

void matrixToSparse(int matrix[ROWS][COLS], struct Sparse *sparse, int *k) {
    *k = 1;
    sparse[0].row = ROWS;
    sparse[0].col = COLS;
    sparse[0].value = 0; 

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[*k].row = i;
                sparse[*k].col = j;
                sparse[*k].value = matrix[i][j];
                (*k)++;
            }
        }
    }
    sparse[0].value = *k - 1;
}

void sparseToMatrix(struct Sparse *sparse, int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= sparse[0].value; i++) {
        matrix[sparse[i].row][sparse[i].col] = sparse[i].value;
    }
}

void sparseTranspose(struct Sparse *sparse, struct Sparse *transposed) {
    int k = 1;
    transposed[0].row = sparse[0].col;
    transposed[0].col = sparse[0].row;
    transposed[0].value = sparse[0].value;
    for (int col = 0; col < sparse[0].col; col++) {
        for (int i = 1; i <= sparse[0].value; i++) {
            if (sparse[i].col == col) {
                transposed[k].row = sparse[i].col;
                transposed[k].col = sparse[i].row;
                transposed[k].value = sparse[i].value;
                k++;
            }
        }
    }
}

int main()
{
    int matrix[4][5] = {
        {1, 0, 0, 0, 0},
        {0, 8, 0, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 4}
    };

    struct Sparse sparse[20];
    int k;
    matrixToSparse(matrix, sparse, &k);
    printf("Tuple representation of the sparse matrix:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    struct Sparse transposed[20];
    sparseTranspose(sparse, transposed);
    printf("Tuple representation of the transposed sparse matrix:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    }

    sparseToMatrix(transposed, matrix);
    printf("Reconstructed Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
