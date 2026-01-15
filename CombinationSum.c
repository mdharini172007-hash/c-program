#include <stdlib.h>

/* Backtracking helper function */
void backtrack(
    int* candidates,
    int candidatesSize,
    int target,
    int start,
    int* path,
    int pathSize,
    int*** result,
    int* returnSize,
    int** returnColumnSizes
) {
    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
        for (int i = 0; i < pathSize; i++)
            (*result)[*returnSize][i] = path[i];
        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    if (target < 0) return;

    for (int i = start; i < candidatesSize; i++) {
        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 200;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int path[100];

    backtrack(candidates, candidatesSize, target, 0, path, 0, &result, returnSize, returnColumnSizes);

    return result;
}
