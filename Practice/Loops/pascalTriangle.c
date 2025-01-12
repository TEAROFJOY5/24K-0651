/*Write a program to produce the following output: 
 *       1
 *     1   1
 *   1   2  1
 *  1  3  3  1
 * 1 4   6  4  1
 */
 #include<stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {  // 5 are the number of rows.
        // Loop for printing leading spaces
        for (int j = 0; j < 5 - i; j++) {
            printf(" ");
        }

        int coefficient = 1; // Initialize the first coefficient
        // Loop for printing numbers in the row
        for (int k = 0; k <= i; k++) {
            printf("%d ", coefficient);
            coefficient = coefficient * (i - k) / (k + 1); // Update the coefficient
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}
