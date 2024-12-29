/*
*Rosaline Scully
 *Student ID: 250966670
 *November 30, 2024
 *
 *This is the main program that puts everything together. It creates a month structure and
 *asks the user for input to fill out the calendar while repeatedly printing the updated calendar.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "reminder.h"
#include "interact.h"

#define MAX_REMINDERS 50  // Max number of reminders
#define MSG_LEN 60        // Max length of reminder message
#define FILE_NAME "reminders.txt"

// Declare the global month structure
struct Month month;
int unsaved_changes = 0; // Flag to track unsaved changes

// Signal handler function
void handle_signal() {
    printf("\nProgram interrupted...\n");
    printf("Writing to file...\n");
    saveAndExit();
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    signal(SIGSEGV, handle_signal);

    int num_reminders = 0;

    initializeMonth();  // Initialize the month details and load reminders from file

    while (1) {
        if (num_reminders == MAX_REMINDERS) {  // If no space left, exit
            printf("--No space left--\n");
            break;
        }

        char msg[MSG_LEN];
        int day = read_reminder(msg, MSG_LEN);  // Read a reminder from the user
        if (day == 0) { //Save and exit
            saveAndExit();
            break;
        }

        addReminder(day, msg);  // Insert the reminder into the calendar
        print_calendar();  // Print the updated calendar
        num_reminders++;  // Update the number of reminders
        unsaved_changes = 1;
    }

    return 0;
}






