#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB ? lenA : lenB) + 2; // +1 for carry, +1 for '\0'

    char *res = (char*)malloc(maxLen * sizeof(char));
    res[maxLen - 1] = '\0';

    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen - 2;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // If result starts with leading zero, move pointer
    return res + k + 1;
}