#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n;
    scanf("%d", &n);

    int sum = 0;

    // Extract and add digits one by one
    sum += n % 10;   // last digit
    n = n / 10;

    sum += n % 10;
    n = n / 10;

    sum += n % 10;
    n = n / 10;

    sum += n % 10;
    n = n / 10;

    sum += n % 10;   // first digit

    printf("%d", sum);

    return 0;
}
