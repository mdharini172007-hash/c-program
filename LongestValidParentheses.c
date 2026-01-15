#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int *stack = (int*)malloc(sizeof(int) * (n + 1));
    int top = -1;
    int maxLen = 0;

    /* push base index */
    stack[++top] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;  // pop

            if (top == -1) {
                /* reset base index */
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    free(stack);
    return maxLen;
}
