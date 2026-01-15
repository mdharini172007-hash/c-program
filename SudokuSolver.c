#include <stdbool.h>

bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        /* check row */
        if (board[row][i] == c) return false;

        /* check column */
        if (board[i][col] == c) return false;

        /* check 3x3 box */
        int r = 3 * (row / 3) + i / 3;
        int d = 3 * (col / 3) + i % 3;
        if (board[r][d] == c) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;

                        if (solve(board))
                            return true;

                        /* backtrack */
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}
