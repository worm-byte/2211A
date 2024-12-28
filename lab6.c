#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplication(int m, int n, int* numbers);
void addition(int m, int n, int* numbers);
void subtraction(int m, int n, int* numbers);
void display(int m, int n, int* numbers);
void freeMemory(int* array);

int main() {
    int n, input;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* numbers = (int*) malloc(3 * n * sizeof(int));

    printf("Enter %d elements: ",n);
    for (int *p = numbers; p < numbers + n; p++) {
        scanf("%d", p);
    }

    srand(time(NULL));
    for (int* p = numbers; p < numbers + 2 * n; p++) {
        *p = rand() % 201;
    }


    do {
        printf("Choose an operation from the following: \n");
        printf("(0) Addition, (1) Subtraction, (2) Multiplication, (4) Quit: ");
        scanf("%d", &input);

        switch (input) {
            case 0:
                addition(3,n,numbers);
            break;
            case 1:
                subtraction(3,n,numbers);
            break;
            case 2:
                multiplication(3,n,numbers);
            break;
            default:
                printf("Incorrect input\n");
        }
    } while(input != 4);

    freeMemory(numbers);
    return 0;
}

void multiplication(int m, int n, int* numbers) {
    int* row1 = numbers;
    int* row2 = numbers + n;
    int* row3 = numbers + 2 * n;

    while (row1 < numbers + n) {
        *row3 = *row1 * *row2;
        row1++;
        row2++;
        row3++;
    }

    display(m, n, numbers);
}

void addition(int m, int n, int* numbers) {
    int* row1 = numbers;
    int* row2 = numbers + n;
    int* row3 = numbers + 2 * n;

    while (row1 < numbers + n) {
        *row3 = *row1 + *row2;
        row1++;
        row2++;
        row3++;
    }
    display(m,n,numbers);
}

void subtraction(int m, int n, int* numbers) {
    int* row1 = numbers;
    int* row2 = numbers + n;
    int* row3 = numbers + 2 * n;

    while (row1 < numbers + n) {
        *row3 = *row1 - *row2;
        row1++;
        row2++;
        row3++;
    }
    display(m,n,numbers);
}

void display(int m, int n, int* numbers) {
    for (int* p = numbers; p < numbers + 3*n; p++) {
        printf("%5d ", *p);
        if ((p-numbers + 1) % n == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void freeMemory(int* array) {
    free(array);
}



