#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Roman values and symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {
        "M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"
    };

    char* result = (char*)malloc(20 * sizeof(char)); // Max length < 20
    result[0] = '\0';

    int i = 0;
    while (num > 0) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
        i++;
    }

    return result;
}
