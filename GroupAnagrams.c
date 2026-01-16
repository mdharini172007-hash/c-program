#include <stdlib.h>
#include <string.h>

// Compare characters for sorting
int charCompare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

// Generate sorted key
char* getKey(char* str) {
    int len = strlen(str);
    char* key = (char*)malloc(len + 1);
    strcpy(key, str);
    qsort(key, len, sizeof(char), charCompare);
    return key;
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes) {

    char*** result = (char***)malloc(strsSize * sizeof(char**));
    char** keys = (char**)malloc(strsSize * sizeof(char*));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < strsSize; i++) {
        char* key = getKey(strs[i]);
        int index = -1;

        // Check existing groups
        for (int j = 0; j < *returnSize; j++) {
            if (strcmp(keys[j], key) == 0) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            // New group
            keys[*returnSize] = key;
            result[*returnSize] = (char**)malloc(strsSize * sizeof(char*));
            result[*returnSize][0] = strs[i];
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        } else {
            // Existing group
            result[index][(*returnColumnSizes)[index]] = strs[i];
            (*returnColumnSizes)[index]++;
            free(key);
        }
    }

    return result;
}
