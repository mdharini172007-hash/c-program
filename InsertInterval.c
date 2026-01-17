#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize,
             int* returnSize, int** returnColSizes) {

    int **res = (int **)malloc((intervalsSize + 1) * sizeof(int *));
    *returnColSizes = (int *)malloc((intervalsSize + 1) * sizeof(int));

    int i = 0, idx = 0;
    int start = newInterval[0], end = newInterval[1];

    // 1. Add intervals before newInterval
    while (i < intervalsSize && intervals[i][1] < start) {
        res[idx] = (int *)malloc(2 * sizeof(int));
        res[idx][0] = intervals[i][0];
        res[idx][1] = intervals[i][1];
        (*returnColSizes)[idx++] = 2;
        i++;
    }

    // 2. Merge overlapping intervals
    while (i < intervalsSize && intervals[i][0] <= end) {
        if (intervals[i][0] < start) start = intervals[i][0];
        if (intervals[i][1] > end)   end   = intervals[i][1];
        i++;
    }

    res[idx] = (int *)malloc(2 * sizeof(int));
    res[idx][0] = start;
    res[idx][1] = end;
    (*returnColSizes)[idx++] = 2;

    // 3. Add remaining intervals
    while (i < intervalsSize) {
        res[idx] = (int *)malloc(2 * sizeof(int));
        res[idx][0] = intervals[i][0];
        res[idx][1] = intervals[i][1];
        (*returnColSizes)[idx++] = 2;
        i++;
    }

    *returnSize = idx;
    return res;
}
