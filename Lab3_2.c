#include <stdio.h>

int main(){
    int numDays, startingDay;

    printf("Enter number of days in month: ");
    scanf("%d", &numDays);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &startingDay);

    for (int i = 1; i < startingDay; i++) {
        printf("      "); 
    }

    for(int day = 1; day <= numDays; day++){

        printf("%6d",day);
        

        if((day + startingDay - 1) % 7 == 0){
            printf("\n");
        }
    }

    printf("\n");
    return 0;



}
