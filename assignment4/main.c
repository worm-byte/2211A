/*
 *Rosaline Scully
 *Student ID: 250966670
 *November 12, 2024
 *
 *This is the main program that puts everything together. It creates a November structure and
 *asks the user for input to fill out the calendar while repeatedly printing the updated calendar.
 */

#include <stdio.h>
#include <string.h>
#include "reminder.h"

#define MAX_REMINDERS 50 //max number of reminders
#define MSG_LEN 60 //max length of reminder message

//declare november structure
struct Month November = {30, 6};

int main(void)
{
    int num_reminders = 0; //keep track of number of reminders

    while(1) {
        if(num_reminders == MAX_REMINDERS) { //if there is no space left exit
            printf("--No space left--\n");
            break;
        }
        char msg[MSG_LEN];
        int day = read_reminder(msg,MSG_LEN); //read a reminder from user
        if(day == 0) break; //if they entered 0 for the date return

        insert_to_calendar(day,msg); //insert reminder into the calendar
        print_calendar(); //print the updated calendar
        num_reminders++; //update the number of reminders

    }
}

