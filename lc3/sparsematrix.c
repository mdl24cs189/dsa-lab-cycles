#include <stdio.h>
#define ROWS 4
#define COLS 5

struct Sparse
{
    int row;
    int col;
    int value;
};

int main()
{
    int matrix[4][5] = {
        {1, 0, 0, 0, 0},
        {0, 8, 0, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 4}
    };

    struct Sparse sparse[20];      
    int k = 1; 


    sparse[0].row = ROWS;
    sparse[0].col = COLS;
    sparse[0].value = 0; 

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0].value = k - 1;

    printf("Tuple representation of the sparse matrix:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
    double sparsity = ((double)(ROWS * COLS - sparse[0].value) / (ROWS * COLS)) * 100;
    printf("Sparsity of matrix is: %.2f%%\n", sparsity);
    return 0;
}
