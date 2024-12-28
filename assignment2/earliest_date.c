/*
Rosaline Scully
Student Number: 250966670

This program will ask the user to enter some dates in mm/dd/yyyy format
and will output the earliest date entered.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//string to int function declaration
int stringToInt(const char *input);

int main() {
    //declare variables
    char date[11];
    int earliestDay = 99;
    int earliestMonth = 99;
    int earliestYear = 99;

    //while loop is true until break statement is reached
    while (1) {
        //prompt user to enter a date
        printf("Enter a date (mm/dd/yy): ");
        scanf("%10s", date);

        //condition to break the loop
        if (strcmp(date, "0/0/0") == 0) {
            break;
        }

        //char variables to hold each section of the date
        char *month = strtok(date, "/");
        char *day = strtok(NULL, "/");
        char *year = strtok(NULL, "/");

        //integer value of each segment
        int monthINT = stringToInt(month);
        int dayINT = stringToInt(day);
        int yearINT = stringToInt(year);

        //update the earliest date if needed
        if (yearINT < earliestYear ||
            (yearINT == earliestYear && monthINT < earliestMonth) ||
            (yearINT == earliestYear && monthINT == earliestMonth && dayINT < earliestDay)) {
            earliestYear = yearINT;
            earliestMonth = monthINT;
            earliestDay = dayINT;
            }
    }
    //output the earliest date
    printf("%02d/%02d/%02d is the earliest date\n", earliestMonth, earliestDay, earliestYear);
    return 0;
}

//turns a string into an int
int stringToInt(const char *input) {
    char *endptr;
    return strtol(input, &endptr, 10);
}







