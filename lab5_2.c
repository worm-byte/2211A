#include <math.h>
#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    double sum1 = 3 * pow(n,5);
    double sum2 = 2 * pow(n,4);
    double sum3 = 5 * pow(n,3);
    double sum4 = pow(n,2);
    double sum5 = 7*n-6;

    long long sum = sum1 + sum2 - sum3 - sum4 + sum5;

    printf("Sum is %.lld\n", sum);

    return 0;
}

