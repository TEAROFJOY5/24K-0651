#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0;
    int atPosition = -1;
    int dotAfterAt = 0;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            atPosition = i;
        }
        if (atCount == 1 && atPosition != -1 && email[i] == '.' && i > atPosition + 1) {
            dotAfterAt = 1;
        }
    }

    return atCount == 1 && atPosition > 0 && dotAfterAt && email[strlen(email) - 1] != '.';
}

int main() {
    char *email;
    int maxLength = 100;
    email = (char*)malloc(maxLength * sizeof(char));
    if (email == NULL) {
        printf("Memory Allocation Failed,\n");
        return 1;
    }

    printf("Enter the email address: \n");
    fgets(email, maxLength, stdin);

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '\n') {
            email[i] = '\0';
            break;
        }
    }

    if (validEmail(email)) {
        printf("Valid email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}
