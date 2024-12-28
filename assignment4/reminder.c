/*
 *Rosaline Scully
 *Student ID: 250966670
 *November 12, 2024
 *This procides the implementation of reminder.h.
 *There are functions to insert reminders into a calendar, read reminder input from a user,
 *and print the calendar.
 */
#include "reminder.h"


/*
Takes a reminder string and a day number and inserts the reminder into the calendar.
Also, sets the reminder flag to true for that day.
 */
void insert_to_calendar(int day, const char* value) {
    if (day < 1 || day > November.month_days) {  //print if user tries to put in a day outside of num days in Nov
         printf("Invalid day. Please enter a day between 1 and %d.\n", November.month_days);
         return;
    }

    strncpy(November.reminder_str[day - 1], value, MAX_STR_LEN - 1);
    November.reminder_str[day - 1][MAX_STR_LEN - 1] = '\0';  // Ensure null-termination
    November.reminders[day - 1] = true;
}

/*
Takes a char array and its length and reads a reminder from the user.
Returns the day number.
 */
int read_reminder(char *str, int n) {
    int day;
    printf("Enter day and reminder (0 to quit): ");


    scanf("%d", &day);  // read day as an integer

    if (day == 0) return 0;  // Exit if day is 0

    getchar();  // get rid of newline character after reading day
    fgets(str, n, stdin);  // read reminder text into str

    // Remove trailing newline character from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    return day;
}

/*
Prints the calendar and the reminders for each day.
 */
void print_calendar() {
    printf(" Sun    Mon   Tue   Wed   Thu   Fri   Sat\n"); //print days of week
    for (int i = 0; i < November.start_day; i++) {
        printf("     "); //proper spacing depending on november start date
    }

    for(int day = 1; day <= 30; day++){ //print days of the month with () around it if it has a reminder
        if(November.reminders[day - 1]) {
            printf(" (%2d) ", day);
        }else {
            printf("  %2d  ", day);
        }

        if((day + November.start_day - 1) % 7 == 0){
            printf("\n"); //newline if at end of the week
        }
    }
    printf("\nReminders: \n"); //print a list of the reminders
    for(int i = 0; i < November.month_days; i++) {
        if(November.reminders[i]) {
            printf("Day %d: %s\n", i + 1, November.reminder_str[i]);
        }
    }
}



