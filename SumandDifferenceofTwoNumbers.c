#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int a, b;
    float x, y;

    // Read two integers
    scanf("%d %d", &a, &b);

    // Read two floats
    scanf("%f %f", &x, &y);

    // Print integer sum and difference
    printf("%d %d\n", a + b, a - b);

    // Print float sum and difference (1 decimal place)
    printf("%.1f %.1f\n", x + y, x - y);

    return 0;
}
