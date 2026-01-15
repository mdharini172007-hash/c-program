#include <stdlib.h>

/* Comparison function for qsort */
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* Backtracking helper */
void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize, int*** result, int* returnSize,
               int** returnColumnSizes) {

    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
        for (int i = 0; i < pathSize; i++)
            (*result)[*returnSize][i] = path[i];
        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue; // skip duplicates
        if (candidates[i] > target) break;
        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1,
                  path, pathSize + 1, result, returnSize, returnColumnSizes);
    }
}

/* Main function for LeetCode */
int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {
    int capacity = 200;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int path[100];

    qsort(candidates, candidatesSize, sizeof(int), cmp); // sort for duplicates
    backtrack(candidates, candidatesSize, target, 0, path, 0,
              &result, returnSize, returnColumnSizes);

    return result;
}
