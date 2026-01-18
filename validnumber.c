#include <stdbool.h>

bool isNumber(char* s) {
    int i = 0;
    bool seenDigit = false;
    bool seenDot = false;
    bool seenExp = false;

    // skip leading spaces (optional safety)
    while (s[i] == ' ') i++;

    // optional sign
    if (s[i] == '+' || s[i] == '-') i++;

    for (; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            seenDigit = true;
        }
        else if (s[i] == '.') {
            if (seenDot || seenExp) return false;
            seenDot = true;
        }
        else if (s[i] == 'e' || s[i] == 'E') {
            if (seenExp || !seenDigit) return false;
            seenExp = true;
            seenDigit = false;   // need digits after exponent

            if (s[i+1] == '+' || s[i+1] == '-') i++;
        }
        else if (s[i] == ' ') {
            // skip trailing spaces
            while (s[i] == ' ') i++;
            return s[i] == '\0';
        }
        else {
            return false;
        }
    }

    return seenDigit;
}
