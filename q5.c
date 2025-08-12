#include <stdio.h>

int main() 
{
    int  r, c, i, j, rowSum, colSum;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int mat[r][c];
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    for (i = 0; i < r; i++) {
        rowSum = 0;
        for (j = 0; j < c; j++)
            rowSum += mat[i][j];
        printf("Sum of row %d = %d\n", i, rowSum);
    }

    for (j = 0; j < c; j++) {
        colSum = 0;
        for (i = 0; i < r; i++)
            colSum += mat[i][j];
        printf("Sum of column %d = %d\n", j, colSum);
    }

    return 0;
}
