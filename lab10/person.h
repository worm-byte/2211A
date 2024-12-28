#ifndef PERSON_H
#define PERSON_H

#include <stdbool.h>

#define MAX_NAME_SIZE 51

// Forward declaration of Node
struct Node;

// Enums for roles and choices
typedef enum { STUDENT, PROFESSOR } RoleType;
typedef enum { ADD = 1, UPDATE, PRINT, DELETE, EXIT } Choice;

// Structs for role-specific data
typedef struct { int StudentId; float GPA; } StudentInfo;
typedef struct { int ProfessorId; double salary; } ProfessorInfo;

// Main person struct
typedef struct {
    RoleType role;
    char name[51];
    union {
        StudentInfo student;
        ProfessorInfo professor;
    } info;
} Person;

// Person-specific functions
bool personExist(struct Node* head, RoleType role, int id);
struct Node* add(struct Node* head);
struct Node* update(struct Node* head);
struct Node* delete(struct Node* head);
void printAllPeople(struct Node* head);
void printPerson(Person* p);

#endif // PERSON_H

