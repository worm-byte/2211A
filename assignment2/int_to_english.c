/*
Rosaline Scully
Student Number: 250966670

This program converts an integer into English.
It will prompt the user to enter an integer, then
it will output how you would say the number in English.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//pointer chars for the functions
char* digitCalc(int n);
char* tensCalc(int n);
char* teenCalc(int n);

int main(){
    //initialized variables
    long num;

    char ones[20];
    char tens[20];
    char hundreds[50];

    bool done;

    printf("Please enter a value (1-999, 0 to quit): ");
    scanf("%ld", &num);


    while(num > 0){
        done = false;
        ones[0] = '\0';
        tens[0] = '\0';
        hundreds[0] = '\0';

        //turns hundreds place into words
        if(num >= 100){
            int hundredsInt = num / 100;
            char* hundredStr = digitCalc(hundredsInt);
            strcat(hundreds, hundredStr);
            strcat(hundreds, " hundred");
            num %= 100;
            if(num > 0){
                strcat(hundreds, " and ");
            }
        }

        //turn 10s place into words if above or equal to 20
        if(num >= 20){
            int tensInt = num / 10;
            char* tensStr = tensCalc(tensInt);
            strcat(tens, tensStr);
            num %= 10;
            if(num > 0){
                strcat(tens, "-");
            }
        } //turn 10s place into words if in the teens
        else if(num >= 10){
            char* teenStr = teenCalc(num);
            strcat(tens, teenStr);
            done = true;
        }

        //if there's still a ones place left, turn it into words (only if 10s place is not a teen number)
        if(num > 0 && !done){
            char* digit = digitCalc(num);
            strcat(ones, digit);
        }

        //continue to scan for input
        printf("You entered the number %s%s%s\n", hundreds, tens, ones);
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%ld", &num);
    }

    return 0;
}

//turn a single digit into word
char* digitCalc(int n){
    char *digits[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if(n >= 0 && n <= 9) return digits[n];
    return "";
}

//turn tens place into word
char* tensCalc(int n){
    char *tensPlace[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if(n >= 0 && n <= 9) return tensPlace[n];
    return "";
}

//turn a teen number into a word
char* teenCalc(int n){
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    if(n >= 10 && n <= 19) return teens[n - 10];
    return "";
}

