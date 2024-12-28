#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> 

#define MAX_NAME_SIZE 51

// Enums for person's role and user's choices
typedef enum {
    STUDENT,
    PROFESSOR
} RoleType;

typedef enum {
    ADD = 1,
    UPDATE = 2,
    PRINT = 3,
    DELETE = 4,
    EXIT = 5
} Choice;

// Structs for student and professor info
typedef struct {
    int StudentId;
    float GPA;
} StudentInfo;

typedef struct {
    int ProfessorId;
    double salary;
} ProfessorInfo;

// Struct to hold person information with role-specific info in a union
typedef struct {
    RoleType role;
    char name[MAX_NAME_SIZE];
    union {
        StudentInfo student;
        ProfessorInfo professor;
    } info;
} Person;

// Node structure for LinkedList
typedef struct Node {
    Person person;
    struct Node* next;
} Node;

// Function prototypes
void printMenu(void);
Node* addPerson(Node* head);
Node* updatePerson(Node* head);
Node* deletePerson(Node* head);
void printAllPeople(Node* head);
void readNames(char* name);
bool personExist(Node* head, RoleType role, int id);
void printPerson(Person* p);

// Main function
int main(void) {
    Node* head = NULL; // Head of the linked list
    int choice;

    do {
        printf("\n");
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case ADD:
                head = addPerson(head);
                break;
            case UPDATE:
                head = updatePerson(head);
                break;
            case PRINT:
                printAllPeople(head);
                break;
            case DELETE:
                head = deletePerson(head);
                break;
            case EXIT:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != EXIT);

    // Free the memory allocated for the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Prints the menu options
void printMenu(void) {
    printf("\nMenu\n");
    printf("1. Add a person\n");
    printf("2. Update a person\n");
    printf("3. Print all people\n");
    printf("4. Delete a person\n");
    printf("5. Exit\n");
}

// Checks if a person with the given role and ID exists
bool personExist(Node* head, RoleType role, int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->person.role == role) {
            if ((role == STUDENT && current->person.info.student.StudentId == id) ||
                (role == PROFESSOR && current->person.info.professor.ProfessorId == id)) {
                return true;
            }
        }
        current = current->next;
    }
    return false;
}

// Adds a new person to the linked list
Node* addPerson(Node* head) {
    int role;
    do {
        printf("Enter the role (0 for student, 1 for professor): ");
        scanf("%d", &role);
        getchar();
        if (role == STUDENT || role == PROFESSOR) break;
        printf("Invalid role - Role must be either 0 or 1.\n");
    }while(1);

    char name[MAX_NAME_SIZE];
    readNames(name);

    if (role == STUDENT) {
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

        if (personExist(head, STUDENT, id)) {
            printf("Student already exists\n");
            return head;
        }
        Person newPerson;
        newPerson.role = (RoleType)role;
        strncpy(newPerson.name, name, MAX_NAME_SIZE - 1);
        newPerson.name[MAX_NAME_SIZE - 1] = '\0';
        newPerson.info.student.StudentId = id;
        newPerson.info.student.GPA = gpa;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->person = newPerson;
        newNode->next = head;
        printf("Student added");
        return newNode;

    }
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

    if (personExist(head, PROFESSOR, id)) {
        printf("Professor with this ID already exists.\n");
        return head;
    }
    Person newPerson;
    newPerson.role = (RoleType)role;
    strncpy(newPerson.name, name, MAX_NAME_SIZE - 1);
    newPerson.name[MAX_NAME_SIZE - 1] = '\0';
    newPerson.info.professor.ProfessorId = id;
    newPerson.info.professor.salary = salary;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->person = newPerson;
    newNode->next = head;
    printf("Professor added");
    return newNode;

}

// Updates an existing person in the linked list
Node* updatePerson(Node* head) {
    printf("Enter the role (0 for student, 1 for professor): ");
    int role;
    scanf("%d", &role);
    getchar();

    char name[MAX_NAME_SIZE];
    readNames(name);

    printf("Enter the ID: ");
    int id;
    scanf("%d", &id);
    getchar();

    Node* current = head;
    while (current != NULL) {
        if (current->person.role == role) {
            if ((role == STUDENT && current->person.info.student.StudentId == id) ||
                (role == PROFESSOR && current->person.info.professor.ProfessorId == id)) {

                if (role == STUDENT) {
                    printf("Enter new GPA: ");
                    scanf("%f", &current->person.info.student.GPA);
                } else {
                    printf("Enter new salary: ");
                    scanf("%lf", &current->person.info.professor.salary);
                }

                if (role == STUDENT) printf("Student updated");
                else printf("Professor updated");
                return head;
            }
        }
        current = current->next;
    }

    printf("Person not found in the database.\n");
    return head;
}

// Deletes a person from the linked list
Node* deletePerson(Node* head) {
    printf("Enter the role (0 for student, 1 for professor): ");
    int role;
    scanf("%d", &role);
    getchar();

    printf("Enter the ID of the person to delete: ");
    int id;
    scanf("%d", &id);
    getchar();

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->person.role == role) {
            if ((role == STUDENT && current->person.info.student.StudentId == id) ||
                (role == PROFESSOR && current->person.info.professor.ProfessorId == id)) {
                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }

                free(current);
                printf("Person deleted successfully.\n");
                return head;
            }
        }
        prev = current;
        current = current->next;
    }

    printf("Person not found in the database.\n");
    return head;
}

// Prints all people in the linked list
void printAllPeople(Node* head) {
    if (head == NULL) {
        printf("No people in the database.\n");
        return;
    }

    Node* current = head;
    printf("People::\n");
    while (current != NULL) {
        printPerson(&current->person);
        current = current->next;
    }
    printf("----------------\n");
}

// Reads a name from user input and ensures it does not contain digits
void readNames(char* name) {
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
                if (isdigit((unsigned char)name[i])) {
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
}


// Prints the details of a person
void printPerson(Person* p) {
    printf("Name: %s,     ", p->name);

    if (p->role == STUDENT) {
        printf("Role: Student,     ");
        printf("Student ID: %d,     ", p->info.student.StudentId);
        printf("GPA: %.2f\n", p->info.student.GPA);
    } else if (p->role == PROFESSOR) {
        printf("Role: Professor,     ");
        printf("Professor ID: %d,     ", p->info.professor.ProfessorId);
        printf("Salary: %.2f\n", p->info.professor.salary);
    }
}

