int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    int *res = (int*)malloc(m * n * sizeof(int));
    int idx = 0;
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // left → right
        for (int j = left; j <= right; j++)
            res[idx++] = matrix[top][j];
        top++;
        
        // top → bottom
        for (int i = top; i <= bottom; i++)
            res[idx++] = matrix[i][right];
        right--;
        
        if (top <= bottom) {
            // right → left
            for (int j = right; j >= left; j--)
                res[idx++] = matrix[bottom][j];
            bottom--;
        }
        
        if (left <= right) {
            // bottom → top
            for (int i = bottom; i >= top; i--)
                res[idx++] = matrix[i][left];
            left++;
        }
    }
    
    *returnSize = idx;
    return res;
}
