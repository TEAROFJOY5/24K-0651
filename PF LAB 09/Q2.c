#include <stdio.h>

void swapIntegers(int *, int *) {
    int *a,*b;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Displaying original values
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Call the swap function made above
    swapIntegers(&num1, &num2);

    // Now displaying the swapped values
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
