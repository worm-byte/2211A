/*
*Rosaline Scully
 *Student ID: 250966670
 *November 30, 2024
 *Header file for linked list functions and Node declaration.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define MAX_STR_LEN 100

// Define the Node structure for storing reminder and day name
struct Node {
    char  message[MAX_STR_LEN]; // Reminder
    char * day_name;
    struct Node* next;       // Pointer to the next node
};

//add a new node to a linked list
struct Node* addNode(struct Node* head, const char* value,const char* day);

//free a linked list of its nodes
void freeAll(struct Node* head);

//Print what's in a linked list
void printList(struct Node* reminders[], int days_in_month);

#endif

