#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColSizes) {
    *returnSize = n;
    *returnColSizes = (int*)malloc(n * sizeof(int));

    int **mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        (*returnColSizes)[i] = n;
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // left → right
        for (int j = left; j <= right; j++)
            mat[top][j] = num++;
        top++;

        // top → bottom
        for (int i = top; i <= bottom; i++)
            mat[i][right] = num++;
        right--;

        if (top <= bottom) {
            // right → left
            for (int j = right; j >= left; j--)
                mat[bottom][j] = num++;
            bottom--;
        }

        if (left <= right) {
            // bottom → top
            for (int i = bottom; i >= top; i--)
                mat[i][left] = num++;
            left++;
        }
    }

    return mat;
}
