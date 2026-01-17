#include <stdbool.h>

bool isSafe(int row, int col, int *cols, int *diag1, int *diag2, int n) {
    if (cols[col]) return false;
    if (diag1[row - col + n - 1]) return false;   // main diagonal
    if (diag2[row + col]) return false;           // anti-diagonal
    return true;
}

void backtrack(int row, int n, int *count,
               int *cols, int *diag1, int *diag2) {

    if (row == n) {
        (*count)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, cols, diag1, diag2, n)) {
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;
            backtrack(row + 1, n, count, cols, diag1, diag2);
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    int cols[20] = {0};
    int diag1[40] = {0};
    int diag2[40] = {0};

    backtrack(0, n, &count, cols, diag1, diag2);
    return count;
}
