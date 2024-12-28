#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[256];
    char *words[50];
    int count = 0;
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';
    char *token = strtok(str, " ");

    while (token != NULL && count < 50) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    printf("Reversed message: ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
