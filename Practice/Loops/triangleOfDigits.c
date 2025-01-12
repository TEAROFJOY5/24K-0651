/*Write a program to produce the following output: 
 *       1 
 *     2  3 
 *   4  5  6 
 * 7  8  9  10
 */
 #include<stdio.h>

int main() {
    int rows=4;
    int num=1;
    for (int i = 1; i <= rows; i++) {
        // Print spaces for centering
        for (int j = 1; j <= rows - i; j++) {
            printf(" "); // Two spaces for better alignment
        }
        for (int k = 1; k <= i; k++) {
            printf("%d ", num);
            num++; // Increment the number
        }

        printf("\n"); // Move to the next row
    }
  return 0;
}
