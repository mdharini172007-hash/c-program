#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize,
               char *current, int pos,
               int open, int close, int n) {

    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, returnSize, current, pos + 1,
                  open + 1, close, n);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, pos + 1,
                  open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;

    // Maximum number of combinations for n <= 8 is 1430
    int capacity = 2000;
    char **result = (char **)malloc(capacity * sizeof(char *));
    char current[2 * n + 1];

    backtrack(result, returnSize, current, 0, 0, 0, n);

    return result;
}