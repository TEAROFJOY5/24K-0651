#include <stdio.h>

int main() {
    int choice, num, fact = 1, i, isPrime = 1;

    printf("\n1. Factorial");
    printf("\n2. Prime");
    printf("\n3. Odd/Even");
    printf("\n4. Exit");
    printf("\nYour choice? ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Factorial Calculation (without loops)
            printf("\nEnter a number: ");
            scanf("%d", &num);
            
            if (num == 0 || num == 1) {
                fact = 1;
            } 
            else if (num == 2) {
                fact = 2;
            } 
            else if (num == 3) {
                fact = 6;
            } 
            else if (num == 4) {
                fact = 24;
            } 
            else if (num == 5) {
                fact = 120;
            } 
            else {
                printf("\nFactorial calculation is limited for small numbers (without loops).");
                return 0;
            }
            printf("\nFactorial: %d", fact);
            break;

        case 2: // Prime Check (without loops)
            printf("\nEnter a number: ");
            scanf("%d", &num);

            if (num <= 1) {
                isPrime = 0;
            } 
            else if (num == 2 || num == 3 || num == 5 || num == 7) {
                isPrime = 1;
            } 
            else if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
                isPrime = 0;
            } 
            else {
                isPrime = 1;
            }

            if (isPrime) {
                printf("\n%d is Prime", num);
            } else {
                printf("\n%d is Not Prime", num);
            }
            break;

        case 3: // Odd/Even Check
            printf("\nEnter a number: ");
            scanf("%d", &num);

            if (num % 2 == 0) {
                printf("\nEven Number");
            } else {
                printf("\nOdd Number");
            }
            break;

        case 4: // Exit
            printf("\nExiting program...");
            return 0;

        default:
            printf("\nInvalid choice! Please enter a valid option.");
    }

    return 0;
}
