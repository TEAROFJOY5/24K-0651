/*Write a program that ask the user to enter the total 'N' no of characters in user's name {First
Name + Last Name} to create a dynamic array of characters. After create a dynamic array of
that 'N' no of characters using malloc or calloc function. Finally copy your full name in it that has
already been taken from the user before
Dynamic Array = "Muhib Ahmed";*/

    
    #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("How many characters are in your full name (without counting spaces)? ");
    scanf("%d", &n);

    getchar(); // to consume the leftover newline character

    char *name = (char *)malloc((n + 1) * sizeof(char)); // +1 for null terminator

    if (name == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter your full name: ");
    fgets(name, n + 1, stdin); // read up to n characters

    printf("Your name is: %s\n", name);

    free(name); // free the memory
    return 0;
}

    
