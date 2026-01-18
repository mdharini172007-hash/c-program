#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char **res = (char **)malloc(wordsSize * sizeof(char*));
    int resIdx = 0;
    int i = 0;

    while (i < wordsSize) {
        int lineLen = 0;
        int start = i;

        // Count how many words fit in the line
        while (i < wordsSize && lineLen + strlen(words[i]) + (i - start) <= maxWidth) {
            lineLen += strlen(words[i]);
            i++;
        }

        int numWords = i - start;
        int numSpaces = maxWidth - lineLen;

        char *line = (char *)malloc((maxWidth + 1) * sizeof(char));
        int pos = 0;

        // Last line or single word: left-justified
        if (i == wordsSize || numWords == 1) {
            for (int j = start; j < i; j++) {
                int len = strlen(words[j]);
                memcpy(line + pos, words[j], len);
                pos += len;
                if (pos < maxWidth) line[pos++] = ' ';
            }
            while (pos < maxWidth) line[pos++] = ' ';
        } else {
            // Fully justify
            int spaceBetween = numSpaces / (numWords - 1);
            int extra = numSpaces % (numWords - 1);

            for (int j = start; j < i; j++) {
                int len = strlen(words[j]);
                memcpy(line + pos, words[j], len);
                pos += len;

                if (j != i - 1) {
                    int sp = spaceBetween + (extra-- > 0 ? 1 : 0);
                    for (int s = 0; s < sp; s++) line[pos++] = ' ';
                }
            }
        }

        line[pos] = '\0';
        res[resIdx++] = line;
    }

    *returnSize = resIdx;
    return res;
}