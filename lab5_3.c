#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    char input[10];
    int numerator1, denominator1, numerator2, denominator2;
    char num1[10] = {0};
    char den1[10] = {0};
    char num2[10] = {0};
    char den2[10] = {0};
    int counter = 0;
    bool d = true;
    bool n = false;
    bool secondFrac = false;

    printf("Enter two fractions separated with a plus sign: ");
    scanf("%scanf9s", input);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '+') {
            secondFrac = true;
            counter = 0;
            d = true;
            n = false;
            continue;
        }
        if (input[i] == '/') {
            d = false;
            n = true;
            counter = 0;
            continue;
        }

        if (!secondFrac && d) {
            num1[counter++] = input[i];
        } else if (!secondFrac && n) {
            den1[counter++] = input[i];
        } else if (secondFrac && d) {
            num2[counter++] = input[i];
        } else if (secondFrac && n) {
            den2[counter++] = input[i];
        }
    }

    numerator1 = atoi(num1);
    denominator1 = atoi(den1);
    numerator2 = atoi(num2);
    denominator2 = atoi(den2);

    int commonDenominator = denominator1 * denominator2;
    int commonNumerator = numerator1 * denominator2 + numerator2 * denominator1;

    printf("The sum is %d/%d\n", commonNumerator, commonDenominator);

    return 0;
}


