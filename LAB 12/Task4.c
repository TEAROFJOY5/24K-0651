/*Write a program that ask the user to enter the total 'N' no of characters in user's name {First
Name + Last Name} to create a dynamic array of characters. After create a dynamic array of
that 'N' no of characters using malloc or calloc function. Finally copy your full name in it that has
already been taken from the user before
Dynamic Array = "Muhib Ahmed";*/

    
    #include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
printf("Enter your full name: ");
fgets(buffer, sizeof(buffer), stdin);
buffer[strcspn(buffer, "\n")] = '\0'; // strip newline

int n = strlen(buffer);
char *name = (char *)malloc((n + 1) * sizeof(char));
strcpy(name, buffer);

printf("Your name is: %s\n", name);
free(name);
}
