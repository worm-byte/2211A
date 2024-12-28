#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "person.h"

// Node structure for linked list
typedef struct Node {
    Person person;
    struct Node* next;
} Node;

// Linked list functions
Node* addPerson(Node* head, Person person);
Node* updatePerson(Node* head, RoleType role, int id);
Node* deletePerson(Node* head, RoleType role, int id);
void printAllPeople(Node* head);
void freeList(Node* head);

#endif // LINKED_LIST_H

