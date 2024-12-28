#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *token;
    int sum = 0;

    fgets(input, 100, stdin);
    token = strtok(input, " ");
    while (token != NULL) {
        int num = atoi(token);
        sum += num;
        token = strtok(NULL, " ");
    }
    printf("Sum: %d\n", sum);
    return 0;
}

