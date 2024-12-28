/*
 * Rosaline Scully
 * Student ID: 250966670
 * Date: October 19, 2024
 *
 * This program asks for user input for numbers to put into an array.
 * It will then prompt the user to decide how they want to sort it
 * or if they want to make any changes.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void arrayFiller(int* array[], int n, int m);
int sortMenu(int* array[], int m);
void bubbleSort(int* row, int m);
void swap(int* a, int* b);
int partition(int* row, int low, int high);
void quickSort(int* row, int low, int high);
void printArray(int* array[], int m, int time);
void copyRow(int* array[], int m);
void freeMatrix(int* array[]);

int main() {
    int n, m;
    int* matrix[2];
    //start of program
    while (1) {
        //scan until user enters appropriate number
        printf("Enter the number of elements you would like to enter (n). n must be an even number: \n");
        scanf("%d", &n);
        if (n % 2 == 1) continue;

        //scan until user enters appropriate number
        bool correct = false;
        while (!correct) {
            printf("Enter the length of the array (m). m must be an even number and >= n: \n");
            scanf("%d", &m);
            if (m % 2 == 0 && m >= n) {
                correct = true;
            }
        }

        //dynamically allocate memory for the columns
        for (int i = 0; i < 2; i++) {
            matrix[i] = (int*)malloc(m * sizeof(int));
        }

        //scan n numbers from user
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &matrix[0][i]);
        }

        //generate random numbers if needed
        int d = m - n;
        printf("You entered %d numbers, %d random numbers will be generated.\n", n, d);
        if(d > 0) { //fill rest of array with random numbers
            arrayFiller(matrix, n, m);
        }

        //copy first row to second
        copyRow(matrix, m);


        int timeTaken = sortMenu(matrix, m); //perform sorting based on user choice and get the time
        printArray(matrix, m, timeTaken); //print both arrays and the time taken

        while(1) {
            char command;
            printf("\nEnter a command from the following list: \n");
            printf("(R) Re-generate random numbers and choose a different sorting algorithm\n");
            printf("(N) Enter another value for n and m, and enter new n numbers\n");
            printf("(S) Use a different sorting algorithm\n");
            printf("(Q) Quit\n");
            scanf(" %c", &command);

            //re-generate random numbers and choose a different sorting algorithm
            if (command == 'R' || command == 'r') {
                printf("You entered %d numbers, %d random numbers will be generated.\n", n, d);
                arrayFiller(matrix, n, m);
                copyRow(matrix, m);
                int timeTaken = sortMenu(matrix, m);
                printArray(matrix, m, timeTaken);
            }else if (command == 'N' || command == 'n') {
                freeMatrix(matrix);//restart from the beginning
                break;
            }else if (command == 'S' || command == 's') { //pick a different sorting algorithm
                copyRow(matrix, m);
                int timeTaken = sortMenu(matrix, m);
                printArray(matrix, m, timeTaken);
            }else if (command == 'Q' || command == 'q') {//exit
                freeMatrix(matrix);
                return 0;
            }else {
                printf("Invalid command. Please try again.\n");
            }
        }

    }
}

//fill the array with random input
void arrayFiller(int* array[], int n, int m) {
    srand(time(NULL));
    for (int i = n; i < m; i++) {
        int randomNum = rand() % 10001;
        array[0][i] = randomNum;
    }

}

//copy one row of the array to another
void copyRow(int* array[], int m) {
    for (int i = 0; i < m; i++) {
        array[1][i] = array[0][i];
    }
}

//display the sorting menu and perform the function
int sortMenu(int* array[], int m) {
    int choice;
    while(1) {
        printf("::Choose a sorting algorithm::\n");
        printf("|| (0)Quick sort | (1)Bubble sort ||\n");
        scanf("%d", &choice);

        if (choice == 0) {
            time_t time1 = time(NULL);
            quickSort(array[1],0,m-1);
            time_t time2 = time(NULL);
            return (int)difftime(time2, time1);
        }
        if (choice == 1) {
            time_t time1 = time(NULL);
            bubbleSort(array[1],m);
            time_t time2 = time(NULL);
            return (int)difftime(time2, time1);
        }
        printf("Invalid choice, try again!");
    }
}

//print the original array and sorted array plus the time it took to sort
void printArray(int* array[], int m, int time) {
    printf("Raw array\n");
    for(int i = 0; i < m; i++) {
        printf("%6d ", array[0][i]);
    }
    printf("\n");
    printf("Sorted array\n");
    for(int i = 0; i < m; i++) {
        printf("%6d ", array[1][i]);
    }
    printf("\n");
    printf("Sorting duration (Sec): %d\n",time);
}

//bubble sort algorithm
void bubbleSort(int* row, int m) {
    for(int i = 0; i < m-1; i++) {
        for(int j = 0; j < m-i-1; j++) {
            if(row[j] > row[j+1]) {
                swap(&row[j], &row[j+1]);
            }
        }
    }
}

// helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// rearranges elements based on the pivot
int partition(int* row,int low, int high) {
    int pivot = row[high];  // Choose the last element as pivot
    int i = low - 1;

    //swaps if element is smaller than pivot
    for (int j = low; j < high; j++) {
        if (row[j] < pivot) {
            i++;
            swap(&row[i], &row[j]);
        }
    }
    //puts pivot in correct position
    swap(&row[i + 1], &row[high]);
    return (i + 1);
}

// Recursive quicksort function for sorting a specific row
void quickSort(int* row, int low, int high) {
    if (low < high) {
        int pi = partition(row, low, high);

        // Recursively sort elements before and after the partition index
        quickSort(row, low, pi - 1);
        quickSort(row, pi + 1, high);
    }
}

void freeMatrix(int* array[]) {
    for (int i = 0; i < 2; i++) {
        free(array[i]);
    }
}

