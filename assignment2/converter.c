/*
Rosaline Scully
Student Number: 250966670

This program can convert from one measuring unit to another.
It can convert between grams and ounces,
square meters and square yards,
iitres and pints,
meter and feet.

It prompts the user to pick which type it would like to convert in between.
Then prompts the user for the value needing to convert.
*/

#include <stdio.h>

int main(){

    //declare variables needed
    int input = 0;
    char conversionType;
    float value;
    float convertedValue;

    while(input != 5){ //prompt the user to enter an input
        printf("What units would you like to convert between? Enter one of the following numbers:\n");
        printf("1 - grams and ounces\n");
        printf("2 - square meters and square yards\n");
        printf("3 - litres and pints\n");
        printf("4 - meter and feet\n");
        printf("5 - quit\n");

        scanf("%d", &input);

        if(input == 1){ //convert between grams and ounces when given direction and value by user
            printf("Pick a conversion direction:\n");
            printf("G - Grams to Ounces\n");
            printf("O - Ounces to Grams\n");
            scanf(" %c", &conversionType);

            if(conversionType == 'G' || conversionType == 'g' || conversionType == 'O' || conversionType == 'o'){
                printf("Please enter a value: ");
                scanf("%f", &value);

                if(conversionType == 'G' || conversionType == 'g'){
                    convertedValue = value/28.34952;
                    printf("Your conversion is %.2f ounces\n", convertedValue);
                }else{
                    convertedValue = value*28.34952;
                    printf("Your conversion is %.2f grams\n", convertedValue);
                }

            }else{
                printf("Please enter a valid input.");
            }
        }else if(input == 2){ //convert between square meters and square yards
            printf("Pick a conversion direction:\n");
            printf("M - Square Meters to Square Yards\n");
            printf("Y - Square Yards to Square Meters\n");
            scanf(" %c", &conversionType);

            if(conversionType == 'M' || conversionType == 'm' || conversionType == 'Y' || conversionType == 'y'){
                printf("Please enter a value: ");
                scanf("%f", &value);

                if(conversionType == 'M' || conversionType == 'm'){
                    convertedValue = value*1.19599;
                    printf("Your conversion is %.2f square yards\n", convertedValue);
                }else{
                    convertedValue = value*0.836127;
                    printf("Your conversion is %.2f square meters\n", convertedValue);
                }
            }else{
                printf("Please enter a valid input.");
            }

        }else if(input == 3){//convert between litres and pints
            printf("Pick a conversion direction:\n");
            printf("L - Litres to Pints\n");
            printf("P - Pints to Litres\n");
            scanf(" %c", &conversionType);

            if(conversionType == 'L' || conversionType == 'l' || conversionType == 'P' || conversionType == 'p'){
                printf("Please enter a value: ");
                scanf("%f", &value);

                if(conversionType == 'L' || conversionType == 'l'){
                    convertedValue = value*2.11338;
                    printf("Your conversion is %.2f pints\n", convertedValue);
                }else{
                    convertedValue = value*0.473176;
                    printf("Your conversion is %.2f\n litres\n", convertedValue);
                }
            }else{
                printf("Please enter a valid input.");
            }
        }else if(input == 4){ //convert between meters and feet
            printf("Pick a conversion direction:\n");
            printf("M - Meters to Feet\n");
            printf("F - Feet to Meters\n");
            scanf(" %c", &conversionType);

            if(conversionType == 'M' || conversionType == 'm' || conversionType == 'F' || conversionType == 'f'){
                printf("Please enter a value: ");
                scanf("%f", &value);

                if(conversionType == 'M' || conversionType == 'm'){
                    convertedValue = value*3.28084;
                    printf("Your conversion is %.2f feet\n", convertedValue);
                }else{
                    convertedValue = value*0.3048;
                    printf("Your conversion is %.2f meters\n", convertedValue);
                }
            }else{
                printf("Please enter a valid input.");
            }

        }else if(input == 5){ //exit condition
            break;
        }else{
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}





