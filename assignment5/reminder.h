/*Rosaline Scully
 *Student ID: 250966670
 *November 30,2024
 *
 *Header file for reminder functions and Month struct declaration.
 */

#ifndef REMINDER_H
#define REMINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "linked_list.h"
#define DAYS_IN_MONTH 31

struct Month {
 int month_idx;  // Month index
 int start_day;  // Start day of the month (0 = Sunday)
 int month_days; // Number of days in the month
 struct Node* reminders[DAYS_IN_MONTH];  // Array of linked lists for reminders
};

//Global variables
extern struct Month month;
extern const char* monthNames[];
extern const char* dayNames[];

//Initializes the month based on current time and previously saved reminders
void initializeMonth(void);

//Adds a reminder to appropriate linked list
void addReminder(int day, const char* value) ;

//Reads a string from user which includes date and reminder. Returns the date.
int read_reminder(char *str, int n) ;

//Prints calendar and reminders for each day
void print_calendar();

//Frees memory of reminders
void freeAllReminders();

#endif
