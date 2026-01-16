#include <stdbool.h>

bool isMatch(char *s, char *p) {
    int i = 0, j = 0;
    int star = -1, match = 0;

    while (s[i]) {
        // Match or '?'
        if (p[j] == s[i] || p[j] == '?') {
            i++;
            j++;
        }
        // '*'
        else if (p[j] == '*') {
            star = j;
            match = i;
            j++;
        }
        // Backtrack if previous '*'
        else if (star != -1) {
            j = star + 1;
            match++;
            i = match;
        }
        // No match
        else {
            return false;
        }
    }

    // Skip remaining '*'
    while (p[j] == '*') {
        j++;
    }

    return p[j] == '\0';
}
