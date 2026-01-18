int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    long long dp[101][101];

    // If starting cell has obstacle
    if (obstacleGrid[0][0] == 1) return 0;

    // Initialize first column
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = (i == 0) ? 1 : dp[i - 1][0];
    }

    // Initialize first row
    for (int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 1)
            dp[0][j] = 0;
        else
            dp[0][j] = (j == 0) ? 1 : dp[0][j - 1];
    }

    // Fill rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return (int)dp[m - 1][n - 1];
}