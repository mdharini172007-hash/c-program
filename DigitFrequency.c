#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[1000];
    int freq[10] = {0};   // array to store frequency of digits 0-9

    scanf("%s", s);

    // Count digit frequencies
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            freq[s[i] - '0']++;   // convert character to digit index
        }
    }

    // Print frequencies
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }

    return 0;
}
