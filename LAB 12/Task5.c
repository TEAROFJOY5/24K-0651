/*Using Task. 4, resize that dynamic array of character and append the array with your studentId.
That student id must be taken input from the user.

DynamicArray = "Muhib Ahmed"; // Before

DynamicArray = "K241234 Muhib Ahmed"; // After the text append */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    char *name, studentId[50];

    
    printf("Enter the number of characters in your name (First + Last Name): ");
    scanf("%d", &num);
    getchar();  

    
    name = (char *)calloc(num + 1, sizeof(char));
    if (name == NULL) {
        printf("Memory Allocation Failed!");
        return 1;
    }

    
    printf("Enter your full name: ");
    fgets(name, num + 1, stdin);
    name[strcspn(name, "\n")] = '\0';  
    


    printf("Enter your Student ID: ");
    fgets(studentId, 50, stdin);
    studentId[strcspn(studentId, "\n")] = '\0';  // Removing the newline character

    
    
    int newSize = strlen(name) + strlen(studentId) + 2;  
    
    name = (char *)realloc(name, newSize * sizeof(char));
    if (name == NULL) {
        printf("Memory Reallocation Failed!");
        return 1;
    }


    memmove(name + strlen(studentId) + 1, name, strlen(name) + 1);  
    
    strncpy(name, studentId, strlen(studentId));  
    
    name[strlen(studentId)] = ' ';              
    


    printf("Updated Dynamic Array: \"%s\"\n", name);


    free(name);

    return 0;
}
