#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* zero = (char*)malloc(2);
        strcpy(zero, "0");
        return zero;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int* result = (int*)calloc(len1 + len2, sizeof(int));

    // Multiply digits
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Convert result array to string
    char* product = (char*)malloc(len1 + len2 + 1);
    int index = 0;
    int i = 0;

    // Skip leading zeros
    while (i < len1 + len2 && result[i] == 0)
        i++;

    while (i < len1 + len2)
        product[index++] = result[i++] + '0';

    product[index] = '\0';

    free(result);
    return product;
}

