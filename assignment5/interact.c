/*
*Rosaline Scully
 *Student ID: 250966670
 *November 30, 2024
 *Implementation of interact.h. There are functions to flush the buffer, read from a file,
 *write to a file, and save the reminders before exiting.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interact.h"

#include "reminder.h"


// Flushes the input buffer
void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Reads from a file if there are any saved reminders
void readFromFile(const char* filename, struct Node* reminders[], int max_days) {
    FILE* file = fopen(filename, "r");  //Read mode
    if (!file) { //If the file doesn't exist, just return
        return;
    }

    char line[256];
    int day;
    char day_name[20];
    char reminder_text[256];

    while (fgets(line, sizeof(line), file)) {
        // Parse line with day index, day name, and reminder
        if (sscanf(line, "%d,%[^,],%[^\n]", &day, day_name, reminder_text) == 3) {
            if (day >= 1 && day <= max_days) {
                reminders[day - 1] = addNode(reminders[day - 1], reminder_text, day_name);
            }
        }
    }
    fclose(file);
}

//Writes new reminders to a file
void writeToFile(const char* filename, struct Node* reminders[], int max_days) {
    FILE* file = fopen(filename, "w"); //Write mode
    if (!file) { //If problem creating file
        perror("Error opening file for writing");
        return;
    }
    //Write reminders
    for (int i = 0; i < max_days; i++) {
        struct Node* current = reminders[i];
        while (current) {
            // Write day index, day name, and reminder message
            fprintf(file, "%d,%s,%s\n", i + 1, current->day_name, current->message);
            current = current->next;
        }
    }
    fclose(file);
}

//Save any unsaved reminders to the file and close the program
void saveAndExit() {
    writeToFile("reminders.txt", month.reminders, DAYS_IN_MONTH);
    freeAllReminders();  // Free allocated memory for linked lists
    exit(0);             // Exit
}


