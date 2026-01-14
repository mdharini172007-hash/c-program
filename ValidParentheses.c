#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else {
            // Stack empty → no matching opening bracket
            if (top == -1)
                return false;

            char open = stack[top--];

            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                return false;
            }
        }
    }

    // Stack should be empty
    return top == -1;
}