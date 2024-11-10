// Create a function that reverses a given string and returns the reversed string. Use this function
// in the main program to display the reversed string entered by the user.


#include <stdio.h>
#include <string.h>

char* reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Reversed string: %s\n", reverseString(str));
    return 0;
}
