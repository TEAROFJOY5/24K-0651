#include <stdio.h>

int main() {
    char str[100];  // Adjust size as needed
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && i < sizeof(str) - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';  // Null-terminate the string

    printf("You entered: %s\n", str);

    return 0;
}
