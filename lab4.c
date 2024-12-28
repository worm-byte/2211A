#include <stdio.h>

int main(void){

    int prompt, hrs, min, minSinceMidnight;

    prompt = 1;

    while(prompt != 0){
        printf("Enter a 24-hour time: ");
        scanf("%d:%d", &hrs, &min);

        minSinceMidnight = hrs*60 + min;

        if(minSinceMidnight < 512){
            printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
        }else if(minSinceMidnight >= 512 && minSinceMidnight < 631){
            printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
        }else if(minSinceMidnight >= 631 && minSinceMidnight < 723){
            printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
        }else if(minSinceMidnight >= 723 && minSinceMidnight < 804){
            printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
        }else if(minSinceMidnight >= 804 && minSinceMidnight < 893){
            printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
        }else if(minSinceMidnight >= 893 && minSinceMidnight < 1043){
            printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
        }else if(minSinceMidnight >= 1043 && minSinceMidnight < 1223){
            printf("Closest departure time is 7:00 p.m., arriving at 9:45 p.m.\n");
        }else if(minSinceMidnight >= 1223 && minSinceMidnight <= 1439){
            printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
        }
        else{
            printf("Not a valid time");
        }

        printf("Enter 1 to continue or 0 to quit: ");
        scanf("%d", &prompt);
        
    }
    
    return 0;
}