#include <stdlib.h>
#include <stdbool.h>

// Compare function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, bool* used,
               int* temp, int tempSize,
               int** result, int* returnSize, int* colSize) {
    if (tempSize == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++)
            result[*returnSize][i] = temp[i];

        colSize[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;

        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = true;
        temp[tempSize] = nums[i];
        backtrack(nums, numsSize, used, temp, tempSize + 1, result, returnSize, colSize);
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int maxPerms = 1;
    for (int i = 1; i <= numsSize; i++)
        maxPerms *= i;

    int** result = (int**)malloc(maxPerms * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));
    *returnSize = 0;

    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    int* temp = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, used, temp, 0, result, returnSize, *returnColumnSizes);

    free(used);
    free(temp);
    return result;
}

