#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* countAndSay(int n) {
    char* curr = (char*)malloc(2);
    strcpy(curr, "1");

    for (int step = 2; step <= n; step++) {
        int len = strlen(curr);
        char* next = (char*)malloc(len * 2 + 1);  // safe size
        int idx = 0;

        for (int i = 0; i < len; i++) {
            int count = 1;
            while (i + 1 < len && curr[i] == curr[i + 1]) {
                count++;
                i++;
            }
            idx += sprintf(next + idx, "%d%c", count, curr[i]);
        }

        free(curr);
        curr = next;
    }
    return curr;
}
