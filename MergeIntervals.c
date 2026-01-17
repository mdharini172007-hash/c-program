#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];   // sort by start time
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int **res = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColSizes = (int *)malloc(intervalsSize * sizeof(int));

    int idx = 0;
    res[0] = (int *)malloc(2 * sizeof(int));
    res[0][0] = intervals[0][0];
    res[0][1] = intervals[0][1];
    (*returnColSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end   = intervals[i][1];

        if (start <= res[idx][1]) {   // overlap
            if (end > res[idx][1])
                res[idx][1] = end;
        } else {
            idx++;
            res[idx] = (int *)malloc(2 * sizeof(int));
            res[idx][0] = start;
            res[idx][1] = end;
            (*returnColSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return res;
}

