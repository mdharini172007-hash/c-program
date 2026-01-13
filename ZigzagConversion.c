#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len)
        return s;

    // Allocate memory for each row
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowLen = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int currRow = 0;
    int direction = -1;

    // Place characters in zigzag rows
    for (int i = 0; i < len; i++) {
        rows[currRow][rowLen[currRow]++] = s[i];

        if (currRow == 0 || currRow == numRows - 1)
            direction = -direction;

        currRow += direction;
    }

    // Combine rows into result string
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowLen[i]; j++) {
            result[index++] = rows[i][j];
        }
        free(rows[i]);
    }

    result[index] = '\0';

    free(rows);
    free(rowLen);

    return result;
}
