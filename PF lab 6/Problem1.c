// while loop is often most effient choice, when it comes to continuously accepting user input until a specific condition is met (like entering zero), his is because a while loop continues to execute as long as a specified condition remains true, which is perfect for scenarios where you don't know how many iterations will occur in advance.

#include <stdio.h>

int main() {
    int value;
    int sum = 0;

    printf("Enter a value (0 to stop): ");

    while (1) {
        scanf("%d", &value); // Get user input
        
        if (value == 0) { 
            break;
        }
        
        sum += value; 
        printf("Current sum: %d\n", sum); 
    }

    printf("Final sum: %d\n", sum); 
    return 0;
}
