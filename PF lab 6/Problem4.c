#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNumber, remainder, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNumber = num;

   
    while (num != 0) {
        remainder = num % 10; 
        sum += pow(remainder, 3); 
        num /= 10; 
    }


    if (sum == originalNumber) {
        printf("%d is an Armstrong number.\n", originalNumber);
    } else {
        printf("%d is not an Armstrong number.\n", originalNumber);
    }

    return 0;
}
