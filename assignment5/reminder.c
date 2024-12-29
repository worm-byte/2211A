/*
 *Rosaline Scully
 *Student ID: 250966670
 *November 30, 2024
 *This provides the implementation of reminder.h.
 *There are functions to insert reminders into a calendar, read reminder input from a user,
 *print the calendar, and free memory.
 */
#include "reminder.h"

#include "interact.h"

//Array of month names and day names
const char* monthNames[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
   };

const char* dayNames[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
   };

//Initializes the month based on current time and previously saved reminders
void initializeMonth(void) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);  // Get current time

    month.month_idx = t->tm_mon;  // Store the current month index

    // Create a new tm structure specifically for the first day of the month
    struct tm first_day = *t;
    first_day.tm_mday = 1;
    first_day.tm_hour = 12;
    first_day.tm_min = 0;
    first_day.tm_sec = 0;

    // Normalize the date
    mktime(&first_day);

    // Get the weekday for the first day
    month.start_day = first_day.tm_wday;

    // Reset the time structure to calculate month days
    first_day = *t;
    first_day.tm_mday = 1;
    first_day.tm_hour = 12;

    month.month_days = 0;
    while (first_day.tm_mon == month.month_idx) {
        month.month_days = first_day.tm_mday;
        first_day.tm_mday++;
        mktime(&first_day);
    }

    // Initialize reminders to NULL for each day
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        month.reminders[i] = NULL;
    }

    // Read existing reminders from the file
    readFromFile("reminders.txt", month.reminders, DAYS_IN_MONTH);
}


//Adds a reminder to appropriate linked list
void addReminder(int day, const char* value) {
    int index = day - 1;
    int weekday_index = (month.start_day + day - 1) % 7;
    month.reminders[index] = addNode(month.reminders[index], value, dayNames[weekday_index]);
}


//Reads a string from user which includes date and reminder. Returns the date.
int read_reminder(char *str, int n) {
    int day;
    do {

        printf("\nEnter day and reminder (0 to quit): ");

        scanf("%d", &day);

        if (day == 0) return 0;  // Exit if day is 0

        if (day > month.month_days || day < 1) {
            printf("Invalid day:: The day must be >= 1 and <= %d days",month.month_days);
        } else {
            getchar();
            fgets(str, n, stdin);
            break;
        }
    } while(1);
    // Remove trailing newline character from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return day;
}

//Prints calendar and reminders for each day
void print_calendar() {
    printf(" Sun    Mon   Tue   Wed   Thu   Fri   Sat\n");

    // Print initial spacing
    for (int i = 0; i <= month.start_day; i++) {
        printf("     ");
    }

    for (int day = 1; day <= month.month_days; day++) {
        // Calculate the correct weekday index
        int weekday_index = (month.start_day + day - 1) % 7;

        if(month.reminders[day - 1] != NULL) {
            printf(" (%2d) ", day);
        } else {
            printf("  %2d  ", day);
        }

        // Check if it's the end of a week
        if (weekday_index == 6) {
            printf("\n");
        }
    }

    // Print reminders for the entire month
    printf("\n%s Reminders:\n", monthNames[month.month_idx]);
    printList(month.reminders, month.month_days);
}

//Frees memory of reminders
void freeAllReminders() {
    for (int i = 0; i < DAYS_IN_MONTH; i++) {
        struct Node* current = month.reminders[i];
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
        month.reminders[i] = NULL;
    }
}







