#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSafe(char **board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void backtrack(int row, int n, char **board,
               char ****res, int *returnSize, int **returnColSizes) {

    if (row == n) {
        (*res)[*returnSize] = (char **)malloc(n * sizeof(char *));
        (*returnColSizes)[*returnSize] = n;

        for (int i = 0; i < n; i++) {
            (*res)[*returnSize][i] = strdup(board[i]);
        }
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            backtrack(row + 1, n, board, res, returnSize, returnColSizes);
            board[row][col] = '.';
        }
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColSizes) {
    *returnSize = 0;
    int capacity = 500;   // enough for n <= 9
    char ***res = (char ***)malloc(capacity * sizeof(char **));
    *returnColSizes = (int *)malloc(capacity * sizeof(int));

    char **board = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    backtrack(0, n, board, &res, returnSize, returnColSizes);

    for (int i = 0; i < n; i++) free(board[i]);
    free(board);

    return res;
}


