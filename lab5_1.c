#include <stdio.h>

int main() {
    char input[4];
    char inputReversed[4];

    printf("Enter a three-digit number: ");
    scanf("%3s", input);

    inputReversed[0] = input[2];
    inputReversed[1] = input[1];
    inputReversed[2] = input[0];
    inputReversed[3] = '\0';

    printf("The reversal is: %s\n",inputReversed);


    return 0;
}

