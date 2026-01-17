#include <stdlib.h>

char* getPermutation(int n, int k) {
    int fact[10];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    int *nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    char *res = (char*)malloc((n + 1) * sizeof(char));
    res[n] = '\0';

    k--;  // convert to 0-based index

    for (int i = 0; i < n; i++) {
        int idx = k / fact[n - 1 - i];
        res[i] = nums[idx] + '0';

        // remove used number
        for (int j = idx; j < n - 1 - i; j++)
            nums[j] = nums[j + 1];

        k %= fact[n - 1 - i];
    }

    free(nums);
    return res;
}
