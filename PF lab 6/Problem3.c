#include <stdio.h>
#include <math.h>

int main() {
    int num, i, isPrime = 1; // Assuming it's a prime number
    int a = 0, b = 1, next;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

   
    if (num <= 1) {
        isPrime = 0; 
    } else {
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0; 
                break;
            }
        }
    }

   
    if (isPrime) {
        printf("%d is a prime number.\n", num);
        
        
        printf("Fibonacci series till %d: ", num);
        if (num >= 0) printf("%d ", a);
        if (num >= 1) printf("%d ", b);
        
        for (next = a + b; next <= num; next = a + b) {
            printf("%d ", next);
            a = b;
            b = next;
        }
        printf("\n");
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
