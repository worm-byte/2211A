#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_SIZE 51
// enum for person's role
typedef enum {
    STUDENT,
    PROFESSOR
} RoleType;

// enum for user's decision
typedef enum {
    ADD = 1,
    UPDATE = 2,
    PRINT = 3,
    DELETE = 4,
    EXIT = 5
} Choice;

// Structs for student of professor info
typedef struct {
    int StudentId;
    float GPA;
} StudentInfo;

typedef struct {
    int ProfessorId;
    double salary;
} ProfessorInfo;

// struct to hold person information with role-specific info in a union
typedef struct {
    RoleType role;        // role of the person (STUDENT or PROFESSOR)
    char name[51];        // name of the person
    union {
        StudentInfo student;     // Information if the person is a student
        ProfessorInfo professor; // Information if the person is a professor
    } info;               // Union to hold either student or professor info
} Person;

//global variables
Person people[100];
int numPeople = 0;

void printMenu(void);
bool personExist(RoleType role, int id);
void addPerson(void);
void updatePerson(void);
void deletePerson(void);
void readNames(char *name);
void printPerson(Person *p);

int main(void) {
    int choice;
    do {
        printf("\n");
        printMenu();  // Print the menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character left by scanf

        switch (choice) {
            case ADD:
                addPerson();
            break;
            case UPDATE:
                updatePerson();
            break;
            case PRINT:
                if (numPeople == 0) {
                    printf("No people in the database to print.\n");
                } else {
                    for (int i = 0; i < numPeople; i++) {
                        printPerson(&people[i]);
                        printf("----------------\n");
                    }
                }
            break;
            case DELETE:
                deletePerson();
            break;
            case EXIT:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != EXIT);
}

// prints the menu options to the user
void printMenu(void) {
    printf("Menu\n");
    printf("1. Add a person\n");
    printf("2. Update a person\n");
    printf("3. Print all people\n");
    printf("4. Delete a person\n");
    printf("5. Exit\n");
}


// This function takes a role and an id and returns a Boolean. It checks if the given role and

// id matches with a person in the array, if a match is found, the function returns true.

// Otherwise, it returns false.

bool personExist(RoleType role, int id) {
    for (int i = 0; i < numPeople; i++) {
        if (people[i].role == role) {
            if(role == STUDENT && people[i].info.student.StudentId == id) {
                return true;
            }
            if(role == PROFESSOR && people[i].info.professor.ProfessorId == id) {
                return true;
            }
        }
    }
    return false;

}

// Asks for the role of the person to be added. Depending on the entered role it will ask the

// user for the student details or the professor details. If a person with the same role and id

// exists in the array, the function will not add this new person.

void addPerson(void) {
    printf("Enter the role (0 for student, 1 for professor): ");
    int role;
    scanf("%d", &role);
    getchar(); // to consume the newline character left by scanf

    if (numPeople >= 100) {
        printf("Database is full, cannot add more people.\n");
        return;
    }

    Person newPerson;

    if (role == 0) { //get student info
        printf("Enter the student's name: ");
        char name[MAX_NAME_SIZE];
        readNames(name);

        printf("Enter the student's ID: ");
        int id;
        scanf("%d", &id);
        getchar();

        printf("Enter the student's GPA: ");
        float GPA;
        scanf("%f", &GPA);
        getchar();

        if(personExist(STUDENT, id)) {
            printf("Student already exists\n");
        } else {
            newPerson.role = STUDENT;
            strncpy(newPerson.name, name, MAX_NAME_SIZE - 1);
            newPerson.name[MAX_NAME_SIZE - 1] = '\0'; // Ensure null termination

            newPerson.info.student.StudentId = id;
            newPerson.info.student.GPA = GPA;

            //add to global array
            people[numPeople] = newPerson;
            numPeople++;
            printf("Student added\n");
        }

    } else if (role == 1) { //get professor info
        printf("Enter the professor's name: ");
        char name[MAX_NAME_SIZE];
        readNames(name);  // Use the readNames function

        printf("Enter the professor's ID: ");
        int id;
        scanf("%d", &id);
        getchar();

        printf("Enter the professor's salary: ");
        float salary;
        scanf("%f", &salary);
        getchar();

        if(personExist(PROFESSOR, id)) {
            printf("Professor already exists\n");
        } else {
            newPerson.role = PROFESSOR;
            strncpy(newPerson.name, name, MAX_NAME_SIZE - 1);
            newPerson.name[MAX_NAME_SIZE - 1] = '\0'; // Ensure null termination

            newPerson.info.professor.ProfessorId = id;
            newPerson.info.professor.salary = salary;

            //add to global array
            people[numPeople] = newPerson;
            numPeople++;
            printf("Professor added\n");
        }
    }else {
        printf("Invalid role. Please try again.\n");
    }
}


// Asks the user for the role and id of the person to be updated.
// Then it searches for that person in the array. If the person exists,
// the function will allow the user to update all the details of this person.
// using new info entered by the user. The information to be updated if the person
// is a student are (name, id, GPA), if the person is a professor,
// the information to be updated are (name, id, salary).

void updatePerson(void) {
    printf("Enter the role (0 for student, 1 for professor): ");
    int role;
    scanf("%d", &role);
    getchar(); // to consume the newline character left by scanf

    printf("Enter the ID of the person you want to update: ");
    int ID;
    scanf("%d", &ID);
    getchar();

    // Search for the person to update
    Person *personToUpdate = NULL;
    for (int i = 0; i < numPeople; i++) {
        if ((role == STUDENT && people[i].role == STUDENT && people[i].info.student.StudentId == ID) ||
            (role == PROFESSOR && people[i].role == PROFESSOR && people[i].info.professor.ProfessorId == ID)) {
            personToUpdate = &people[i];
            break;
        }
    }

    if (personToUpdate != NULL) { // Found the person to update
        printf("Enter the new name: ");
        char name[MAX_NAME_SIZE];
        readNames(name);
        strncpy(personToUpdate->name, name, MAX_NAME_SIZE - 1);
        personToUpdate->name[MAX_NAME_SIZE - 1] = '\0'; // Ensure null termination

        if (role == STUDENT) {
            printf("Enter the new student's ID: ");
            int newId;
            scanf("%d", &newId);
            getchar();

            printf("Enter the new GPA: ");
            float GPA;
            scanf("%f", &GPA);
            getchar();

            // Update student-specific info
            personToUpdate->info.student.StudentId = newId;
            personToUpdate->info.student.GPA = GPA;

            printf("Student updated successfully.\n");

        } else if (role == PROFESSOR) {
            printf("Enter the new professor's ID: ");
            int newId;
            scanf("%d", &newId);
            getchar();

            printf("Enter the new salary: ");
            float salary;
            scanf("%f", &salary);
            getchar();

            // Update professor-specific info
            personToUpdate->info.professor.ProfessorId = newId;
            personToUpdate->info.professor.salary = salary;

            printf("Professor updated successfully.\n");
        }

    } else {
        printf("Person not found in the database.\n");
    }
}




// The function asks the user for the role and id of a person in the database. If a match is

// found, the item will be removed from the array.

void deletePerson(void) {
    printf("Enter the role (0 for student, 1 for professor): ");
    int role;
    scanf("%d", &role);
    getchar();

    printf("Enter the ID of the person you want to delete: ");
    int ID;
    scanf("%d", &ID);

    // Find the index of the person to delete
    int index = -1;
    for (int i = 0; i < numPeople; i++) {
        if ((role == 0 && people[i].role == STUDENT && people[i].info.student.StudentId == ID) ||
            (role == 1 && people[i].role == PROFESSOR && people[i].info.professor.ProfessorId == ID)) {
            index = i;
            break;
            }
    }

    // If person exists, remove them from the array
    if (index != -1) {
        for (int i = index; i < numPeople - 1; i++) {
            people[i] = people[i + 1];
        }
        numPeople--; // Decrement the number of people after removal
        printf("Person removed from the database.\n");
    } else {
        printf("Person not found in the database.\n");
    }
}

// This is a custom string reading function. It will read and discard white-spaces that are

// found in the buffer before characters. It will read until it finds a ‘\n’, but will only store up to

// 50 characters in the character array passed as argument.

void readNames(char *name) {
    if (fgets(name, MAX_NAME_SIZE, stdin)) {
        size_t length = strlen(name);
        if (length > 0 && name[length - 1] == '\n') {
            name[length - 1] = '\0';
        }
    }
}

// prints the information of the given person.

// When p is a pointer to a struct, you can access the members of this struct using the arrow operator (->)

void printPerson(Person *p) {
    printf("\n");
    printf("Name: %s\n", p->name);

    if (p->role == STUDENT) {
        printf("Role: Student     ");
        printf("Student ID: %d     ", p->info.student.StudentId);
        printf("GPA: %.2f\n", p->info.student.GPA);
    } else if (p->role == PROFESSOR) {
        printf("Role: Professor     ");
        printf("Professor ID: %d     ", p->info.professor.ProfessorId);
        printf("Salary: %.2f\n", p->info.professor.salary);
    }
}

