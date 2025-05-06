/*Using Task. 4, resize that dynamic array of character and append the array with your studentId.
That student id must be taken input from the user.

DynamicArray = "Muhib Ahmed"; // Before

DynamicArray = "K241234 Muhib Ahmed"; // After the text append */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int nameLength;
    char *fullName;
    char studentId[50];

    // Ask how many characters are in the user's name
    printf("Enter number of characters in your full name: ");
    scanf("%d", &nameLength);
    getchar();  // clear the newline from input buffer

    // Allocate memory for the name
    fullName = (char *)malloc((nameLength + 1) * sizeof(char)); // +1 for null terminator
    if (fullName == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Take name input
    printf("Enter your full name: ");
    fgets(fullName, nameLength + 1, stdin);
    fullName[strcspn(fullName, "\n")] = '\0'; // remove newline

    // Take student ID input
    printf("Enter your Student ID: ");
    fgets(studentId, sizeof(studentId), stdin);
    studentId[strcspn(studentId, "\n")] = '\0'; // remove newline

    // Calculate new size for combined string
    int newLength = strlen(studentId) + 1 + strlen(fullName) + 1;

    // Resize memory to fit ID + space + name
    fullName = (char *)realloc(fullName, newLength * sizeof(char));
    if (fullName == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Move the original name to make space for ID + space
    memmove(fullName + strlen(studentId) + 1, fullName, strlen(fullName) + 1);

    // Copy ID and space at the start
    strncpy(fullName, studentId, strlen(studentId));
    fullName[strlen(studentId)] = ' ';

    // Print final result
    printf("Updated Dynamic Array: \"%s\"\n", fullName);

    free(fullName); // Free the memory
    return 0;
}

