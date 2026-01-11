#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[1000];

    // Read a line of input from stdin
    fgets(s, sizeof(s), stdin);

    // Print the required output
    printf("Hello, World!\n");
    printf("%s", s);

    return 0;
}
