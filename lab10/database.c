#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "interact.h"
#include "linked_list.h"
#include "person.h"

// Global pointer to the head of the linked list
Node* head = NULL;

// Signal handler function
void handleSignal(int signal) {
    if (signal == SIGINT) {
        printf("\nReceived SIGINT (Ctrl+C). Cleaning up and exiting...\n");
    } else if (signal == SIGTERM) {
        printf("\nReceived SIGTERM. Cleaning up and exiting...\n");
    }

    // Free the linked list
    freeList(head);
    head = NULL;

    // Exit the program
    exit(EXIT_SUCCESS);
}

int main(void) {
    // Register signal handlers
    signal(SIGINT, handleSignal);
    signal(SIGTERM, handleSignal);

    Choice choice;

    do {
        printf("\n");
        printMenu();
        choice = getChoice();

        switch (choice) {
            case ADD: {
                head = add(head);
                break;
            }
            case UPDATE: {
                head = update(head);
                break;
            }
            case PRINT: {
                printAllPeople(head);
                break;
            }
            case DELETE: {
                head = delete(head);
                break;
            }
            case EXIT:
            break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != EXIT);

    // Free dynamically allocated memory
    freeList(head);

    return 0;
}

