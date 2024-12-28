#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplication(int m, int n, int numbers[m][n]);
void addition(int m, int n, int numbers[m][n]);
void subtraction(int m, int n, int numbers[m][n]);
void display(int m, int n, int numbers[m][n]);

int main() {
    int n, input;
    int counter = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int numbers[3][n];

    printf("Enter %d elements: ",n);
    while (counter < n) {
        scanf("%d", &numbers[0][counter]);
        counter++;
    }

    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        numbers[1][i] = rand() % 201; // Generate random numbers between 0 and 200
    }

    printf("Choose an operation from the following: \n");
    printf("(0) Addition, (1) Subtraction, (2) Multiplication, (4) Quit: ");
    scanf("%d", &input);

    while (input != 4) {
        switch (input) {
            case 0:
                addition(3, n, numbers);
                break;
            case 1:
                subtraction(3, n, numbers);
                break;
            case 2:
                multiplication(3, n, numbers);
                break;
            default:
                printf("Incorrect input\n");
                break;
        }
        printf("Pick one of the following options: \n");
        printf("(0) Addition, (1) Subtraction, (2) Multiplication, (4) Quit\n");
        scanf("%d", &input);
    }

    return 0;
}

void multiplication(int m, int n, int numbers[m][n]) {
    for (int j = 0; j < n; j++) {
        numbers[2][j] = numbers[0][j] * numbers[1][j];
    }
    display(m, n, numbers);
}

void addition(int m, int n, int numbers[m][n]) {
    for (int j = 0; j < n; j++) {
        numbers[2][j] = numbers[0][j] + numbers[1][j];
    }
    display(m, n, numbers);
}

void subtraction(int m, int n, int numbers[m][n]) {
    for (int j = 0; j < n; j++) {
        numbers[2][j] = numbers[0][j] - numbers[1][j];
    }
    display(m, n, numbers);
}

void display(int m, int n, int numbers[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", numbers[i][j]);
        }
        printf("\n");
    }
}

