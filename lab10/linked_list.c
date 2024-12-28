#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


Node* addPerson(Node* head, Person person) {
    Node* newNode = malloc(sizeof(Node));
    newNode->person = person;
    newNode->next = head;
    return newNode;
}
Node* updatePerson(Node* head, RoleType role, int id) {
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
Node* deletePerson(Node* head, RoleType role, int id) {
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
                printf("Person deleted\n");
                return head;
            }
        }
        prev = current;
        current = current->next;
    }

    printf("Person not found in the database.\n");
    return head;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
