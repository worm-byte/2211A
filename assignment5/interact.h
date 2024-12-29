/*
*Rosaline Scully
 *Student ID: 250966670
 *November 30, 2024
 *Header file for interact functions.
 */
#ifndef INTERACT_H
#define INTERACT_H

#include "linked_list.h"

//Empties the buffer when needed
void flushBuffer();

//Reads data saved in a file
void readFromFile(const char* filename, struct Node* reminders[], int max_days);

//Writes new reminders to a file
void writeToFile(const char* filename, struct Node* reminders[], int max_days);

//Save any unsaved reminders to the file and close the program
void saveAndExit();

#endif

