#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "person.h"
#include "interact.h"

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
Node* add(Node* head) {
    int role = getRole();
    char name[MAX_NAME_SIZE];
    char * newName = getName(name);

    if (role == STUDENT) {
        int id = getId();
        float gpa = getGPA();

        if (personExist(head, STUDENT, id)) {
            printf("Student already exists\n");
            return head;
        }

        Person person;
        person.role = role;
        strncpy(person.name, newName, MAX_NAME_SIZE - 1);
        person.name[MAX_NAME_SIZE - 1] = '\0';
        person.info.student.StudentId = id;
        person.info.student.GPA = gpa;

        Node* newNode = addPerson(head, person);
        printf("Student added");
        return newNode;

    }

    int id = getId();
    float salary = getSalary();

    if (personExist(head, PROFESSOR, id)) {
        printf("Professor already exists\n");
        return head;
    }

    Person person;
    person.role = role;
    strncpy(person.name, newName, MAX_NAME_SIZE - 1);
    person.name[MAX_NAME_SIZE - 1] = '\0';
    person.info.professor.ProfessorId = id;
    person.info.professor.salary = salary;

    Node* newNode = addPerson(head, person);
    printf("Professor added");
    return newNode;

}
Node* update(Node* head) {
    int role = getRole();
    char name[MAX_NAME_SIZE];
    char * newName = getName(name);
    int id = getId();

    Node* newHead = updatePerson(head,role,id);

    return newHead;


}
Node* delete(Node* head){
    int role = getRole();
    char name[MAX_NAME_SIZE];
    char * newName = getName(name);
    int id = getId();
    Node* newHead = deletePerson(head,role,id);
    return newHead;
}
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

