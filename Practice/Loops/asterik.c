/* Write a program that print the following pattern
   * * * * *
   *       *
   *       *
   * * * * *
 */
#include <stdio.h>

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            // Print '*' at the borders
            if (i == 0 || i == 3 || j == 0 || j == 4) {
                printf("* ");
            } else {
                // Print space for the inner part
                printf("  ");
            }
        }
        printf("\n"); // Move to the next row
    }
    return 0;
}
