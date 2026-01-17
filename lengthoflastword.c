#include <string.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = len - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
        i--;

    int count = 0;
    // Count last word length
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}
