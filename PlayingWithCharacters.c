#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char ch;
    char s[100];
    char sen[100];

    // Read character
    scanf("%c", &ch);

    // Read string (no spaces)
    scanf("%s", s);

    // Clear newline before reading sentence
    scanf("\n");

    // Read full sentence (with spaces)
    scanf("%[^\n]%*c", sen);

    // Print outputs
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}