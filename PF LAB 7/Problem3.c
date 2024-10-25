#include <stdio.h>

int main() {
    char str[100];
    char *start, *end, temp;
    int length = 0;

    printf("Enter a string: ");
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;  // Store each character in the array
    }
    str[i] = '\0';  // Null-terminate the string

    // Calculate length using pointers
    start = str;  // Point to the beginning of the string
    while (*start != '\0') {  // Check for null terminator
        length++;
        start++;
    }

     end = str + length - 1;
    start = str;  // Reset start to the beginning 
    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    
    printf("Reversed string: %s\n", str);

    return 0;
}
