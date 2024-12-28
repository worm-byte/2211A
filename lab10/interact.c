#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "interact.h"

void printMenu(void) {
    printf("\nMenu\n");
    printf("1. Add a person\n");
    printf("2. Update a person\n");
    printf("3. Print all people\n");
    printf("4. Delete a person\n");
    printf("5. Exit\n");
}

Choice getChoice(void) {
    int choice;
    while (true) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1 && choice >= ADD && choice <= EXIT) {
            getchar();
            return choice;
        }
        printf("Invalid choice\n");
        printMenu();
        while (getchar() != '\n');
    }
}

RoleType getRole(void) {
    int role;
    do {
            printf("Enter the role (0 for student, 1 for professor): ");
            scanf("%d", &role);
            getchar();
            if (role == STUDENT || role == PROFESSOR) break;
            printf("Invalid role - Role must be either 0 or 1.\n");
        }while(1);
    return role;
}
char* getName(char* name) {
    while (true) {
        printf("Enter the name: ");
        if (fgets(name, MAX_NAME_SIZE, stdin)) {
            size_t length = strlen(name);
            if (length > 0 && name[length - 1] == '\n') {
                name[length - 1] = '\0';
            }

            // Check if the name contains any digits
            bool hasDigit = false;
            for (size_t i = 0; i < strlen(name); i++) {
                if (isdigit(name[i])) {
                    hasDigit = true;
                    break;
                }
            }

            if (!hasDigit) {
                break; // Exit the loop if the name is valid
            }
            printf("Invalid name - Names cannot contain numbers.\n");
        }
    }
    return name;
}

int getId(void) {
    int id;
    do {
        printf("Enter the ID: ");
        if (scanf("%d", &id) == 1) {
            if(id > 0) {
                getchar();
                break;
            }
        }
        printf("Invalid ID - ID must be a positive number\n");
        while(getchar() != '\n');
    }while(1);
    return id;
}
float getGPA(void) {
    float gpa;
    do {
        printf("Enter the GPA: ");
        if (scanf("%f", &gpa) == 1) {
            getchar();
            break;
        }
        printf("Invalid ID - GPA must be a number\n");
        while(getchar() != '\n');
    }while(1);
    return gpa;
}
float getSalary(void) {
    float salary;
    do {
        printf("Enter the salary: ");
        if (scanf("%f", &salary) == 1) {
            getchar();
            break;
        }
        printf("Invalid salary - Salary must be integers of floating-point number\n");
        while(getchar() != '\n');
    }while(1);
    return salary;
}


