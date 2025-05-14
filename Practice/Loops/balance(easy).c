/*
  (Calculating Credit Limits) Collecting money becomes increasingly difficult during peri
ods of recession, so companies may tighten their credit limits to prevent their accounts receivable
 (money owed to them) from becoming too large. In response to a prolonged recession, one company
 has cut its customers’ credit limits in half. Thus, if a particular customer had a credit limit of $2000,
 it’s now $1000. If a customer had a credit limit of $5000, it’s now $2500. Write a program that
 analyzes the credit status of three customers of this company. For each customer you’re given:
 a) The customer’s account number
 b) The customer’s credit limit before the recession
 c) The customer’s current balance (i.e., the amount the customer owes the company).
 Your program should calculate and print the new credit limit for each customer and should
 determine (and print) which customers have current balances that exceed their new credit limits.
*/
#include <stdio.h>

int main() {
    int accountNumber;
    float oldLimit, newLimit, balance;

    for (int i = 1; i <= 3; i++) {
        // Input customer data
        printf("\nEnter account number for customer %d: ", i);
        scanf("%d", &accountNumber);

        printf("Enter original credit limit: ");
        scanf("%f", &oldLimit);

        printf("Enter current balance: ");
        scanf("%f", &balance);

        // Calculate new credit limit
        newLimit = oldLimit / 2;

        // Output
        printf("Account %d: New credit limit is %.2f\n", accountNumber, newLimit);

        if (balance > newLimit) {
            printf("-> Warning: Balance %.2f exceeds new credit limit!\n", balance);
        }
    }

    return 0;
}
