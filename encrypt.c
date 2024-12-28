#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char encrypter(char letter, int shift);

int main() {
    char message[1024];
    int shift;

    fgets(message, sizeof(message), stdin);

    //find the shift value at the end of the line and remove it
    message[strcspn(message, "\n")] = '\0';
    int len = strlen(message);
    int end = len - 1;
    while (end >= 0 && message[end] != ' ') {
        end--;
    }
    shift = atoi(&message[end + 1]);
    message[end] = '\0';

    printf("Encrypted message: ");
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch == ' ') {
            printf(" "); 
        } else {
            printf("%c", encrypter(ch, shift));
        }
    }
    printf("\n");

    return 0;
}

char encrypter(char letter, int shift) {
    if (isupper(letter)) {
        return (letter - 'A' + shift + 26) % 26 + 'A';
    }
    if (islower(letter)) {
        return (letter - 'a' + shift + 26) % 26 + 'a';
    }
    return letter;
}

