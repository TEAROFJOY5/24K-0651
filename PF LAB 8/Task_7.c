#include <stdio.h>

int main() {
    int rows, i, j, coefficient;

   // The number of rows to print
    rows = 5; 

    for (i = 0; i < rows; i++) {
        coefficient = 1; // The first coefficient in each row

        // Print leading spaces 
        for (j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // Print the coefficients for the current row
        for (j = 0; j <= i; j++) {
            printf("%d ", coefficient);
            coefficient = coefficient * (i - j) / (j + 1); // Calculate the next coefficient
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}
