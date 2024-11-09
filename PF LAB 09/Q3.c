#include <stdio.h>

// Function made to check  that if a number is prime
int prime(int num) {
    // A prime number is greater than 1
    if (num <= 1) {
        return 0;  // End the program when the number is negative.
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // End the program, if num is divisible by i
        }
    }

    return 1;  // Number is even
}

int main() {
    int number;
    printf("Enter an integer to check if it's prime: ");
    scanf("%d", &number);
    if (prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
