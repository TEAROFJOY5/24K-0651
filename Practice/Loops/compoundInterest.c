/*(Modified Compound-Interest Program) Modify the compound-interest program of
 * Section 4.6 to repeat its steps for interest rates of 5%, 6%, 7%, 8%, 9%, and 10%. Use a for loop
 * to vary the interest rate.
 *
 */
// Modified Compound-Interest Program
#include <stdio.h>
#include <math.h> // Needed for the pow function

int main(void) {
    double amount;                   // Amount on deposit
    double principal = 1000.0;       // Starting principal
    double rate;                     // Annual interest rate
    unsigned int year;               // Year counter
    int percentage;                  // Rate as integer percentage

    // Loop through interest rates from 5% to 10%
    for (percentage = 5; percentage <= 10; ++percentage) {
        rate = percentage / 100.0;  // Convert percentage to decimal

        // Output the table header for current rate
        printf("\nInterest Rate: %d%%\n", percentage);
        printf("%4s%21s\n", "Year", "Amount on deposit");

        // Calculate amount on deposit for each of ten years
        for (year = 1; year <= 10; ++year) {
            amount = principal * pow(1.0 + rate, year);  //calculates the compound interest for a given year using the compound interest formula:
            printf("%4u%21.2f\n", year, amount);
        }
    }

    return 0;
}
