#include <stdlib.h>

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Backtracking helper
void backtrack(int* nums, int numsSize, int start,
               int** result, int* returnSize, int* colSize) {
    if (start == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++)
            result[*returnSize][i] = nums[i];

        colSize[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, result, returnSize, colSize);
        swap(&nums[start], &nums[i]);  // backtrack
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPerms = 1;
    for (int i = 1; i <= numsSize; i++)
        maxPerms *= i;  // n!

    int** result = (int**)malloc(maxPerms * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, result, returnSize, *returnColumnSizes);
    return result;
}

