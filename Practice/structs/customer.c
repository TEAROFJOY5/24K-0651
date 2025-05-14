#include <stdio.h>

// Define a structure to hold customer data
struct Customer {
    int accountNumber;
    float oldLimit;
    float newLimit;
    float balance;
};

int main() {
    int i, totalCustomers = 3;
    struct Customer customers[totalCustomers];  // Array of structs

    // Input data for each customer
    for (i = 0; i < totalCustomers; i++) {
        printf("\nCustomer %d\n", i + 1);

        printf("Enter account number: ");
        scanf("%d", &customers[i].accountNumber);

        printf("Enter old credit limit: ");
        scanf("%f", &customers[i].oldLimit);

        printf("Enter current balance: ");
        scanf("%f", &customers[i].balance);

        // Calculate new limit
        customers[i].newLimit = customers[i].oldLimit / 2;
    }

    // Display results
    printf("\n--- Credit Limit Report ---\n");
    for (i = 0; i < totalCustomers; i++) {
        printf("\nAccount Number: %d\n", customers[i].accountNumber);
        printf("Old Credit Limit: %.2f\n", customers[i].oldLimit);
        printf("New Credit Limit: %.2f\n", customers[i].newLimit);
        printf("Current Balance: %.2f\n", customers[i].balance);

        if (customers[i].balance > customers[i].newLimit) {
            printf("-> Warning: Balance exceeds new credit limit!\n");
        } else {
            printf("-> Status: Within credit limit.\n");
        }
    }

    return 0;
}
