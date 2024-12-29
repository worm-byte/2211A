/*
*Rosaline Scully
 *Student ID: 250966670
 *November 30, 2024
 *Implementation of linked_list.h. There are functions to add a node, free nodes, and
 *print a list of nodes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#include "reminder.h"

//add a new node to a linked list
struct Node* addNode(struct Node* head, const char* value,const char* day) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->message, value, MAX_STR_LEN - 1);
    newNode->message[MAX_STR_LEN - 1] = '\0';
    newNode->next = NULL;
    newNode->day_name = (char*)day;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

//free a linked list of its nodes
void freeAll(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

//Print what's in a linked list
void printList(struct Node* reminders[], int days_in_month) {
    for (int day = 0; day < days_in_month; day++) {
        if (reminders[day] != NULL) {  // Check if there are reminders for the day
            // Calculate the correct weekday index
            int weekday_index = (month.start_day + day) % 7;

            if (day+1 >= 10) { //For spacing properly
                printf("%s %d:: ", dayNames[weekday_index], day + 1);
            }
            else {
                printf("%s  %d:: ", dayNames[weekday_index], day + 1);
            }

            struct Node* current = reminders[day];  // Get the head of the linked list for this day
            int counter = 1;
            if (current != NULL) {
                printf("(%d) %s\n", counter, current->message); //Print out the reminder
                current = current->next;
                counter++;
            }
            while (current != NULL) {
                printf("         (%d) %s\n", counter, current->message);  // Print the reminder with extra spacing
                current = current->next;  // Move to the next node in the list
                counter++;
            }
        }
    }
}


