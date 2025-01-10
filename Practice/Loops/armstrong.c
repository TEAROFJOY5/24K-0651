/* Write a program to print out all Armstrong numbers between 
   1 and 500. If sum of cubes of each digit of the number is 
   equal to the number itself, then the number is called an 
   Armstrong number. For example, 153 = ( 1 * 1 * 1 ) + ( 5 * 5 
   * 5 ) + ( 3 * 3 * 3 )
 */
 
 #include <stdio.h>

int main() {
    int num, originalNum, remainder, sum;

    // Loop through numbers from 1 to 500
    for (num = 1; num <= 500; num++) {
        originalNum = num;  // Store the original number
        sum = 0;  // Reset sum for each number

        // Extract digits and compute the sum of cubes
        while (originalNum != 0) {
            remainder = originalNum % 10;  // Get the last digit
            sum += remainder * remainder * remainder;  // Add the cube of the digit
            originalNum /= 10;  // Remove the last digit
        }

        // Check if the sum of cubes equals the original number
        if (sum == num) {
            printf("%d is an Armstrong number.\n", num);
        }
    }

    return 0;
}
