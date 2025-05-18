#include <stdio.h>
#include <string.h>

typedef struct customerData {
    int accountNum;
    char name[8];
    float currentBalance;
} Customer;

typedef struct transactionData {
    int accountNum;
    float Amount;
} Transaction;

int main() {
    Customer customer;
    FILE *ofptr;
    ofptr = fopen("oldmast.dat", "rb+");

    if (!ofptr) {
        ofptr = fopen("oldmast.dat", "wb+");
        if (ofptr) {
            customer.accountNum = 0;
            strcpy(customer.name, "");
            customer.currentBalance = 0.0;
            for (int i = 0; i < 100; i++) {
                fwrite(&customer, sizeof(Customer), 1, ofptr);
            }
        } else {
            printf("File creation failed!\n");
            return 0;
        }
    }

    printf("Creating oldmast.dat (master file)...\n");

    printf("\nEnter account number (1 to 100), 0 to end the input: ");
    scanf("%d", &customer.accountNum);
    while (customer.accountNum != 0 && customer.accountNum <= 100) {
        printf("\nEnter customer name and their balance: ");
        scanf("%s %f", customer.name, &customer.currentBalance);

        fseek(ofptr, (customer.accountNum - 1) * sizeof(Customer), SEEK_SET);
        fwrite(&customer, sizeof(Customer), 1, ofptr);

        printf("\nEnter account number (1 to 100), 0 to end the input: ");
        scanf("%d", &customer.accountNum);
    }
    fclose(ofptr);

    Transaction transaction;
    FILE *tfptr;
    tfptr = fopen("trans.dat", "rb+");

    if (!tfptr) {
        tfptr = fopen("trans.dat", "wb+");
        if (tfptr) {
            transaction.accountNum = 0;
            transaction.Amount = 0.0;
            for (int i = 0; i < 100; i++) {
                fwrite(&transaction, sizeof(Transaction), 1, tfptr);
            }
        } else {
            printf("File creation failed!\n");
            return 0;
        }
    }

    printf("Creating trans.dat (transaction file)...\n");

    printf("\nEnter account number (1 to 100), 0 to end the input: ");
    scanf("%d", &transaction.accountNum);
    while (transaction.accountNum != 0 && transaction.accountNum <= 100) {
        printf("\nEnter transaction amount: ");
        scanf("%f", &transaction.Amount);
        fseek(tfptr, (transaction.accountNum - 1) * sizeof(Transaction), SEEK_SET);
        fwrite(&transaction, sizeof(Transaction), 1, tfptr);

        printf("\nEnter account number (1 to 100), 0 to end the input: ");
        scanf("%d", &transaction.accountNum);
    }
    fclose(tfptr);

    // Reopen files for reading
    ofptr = fopen("oldmast.dat", "rb");
    tfptr = fopen("trans.dat", "rb");
    FILE *nfptr = fopen("newmast.dat", "wb+");

    if (!nfptr) {
        printf("\nOpening newmast.dat failed!");
        return 1;
    }

    rewind(ofptr);
    while (fread(&customer, sizeof(Customer), 1, ofptr)) {
        rewind(tfptr);
        while (fread(&transaction, sizeof(Transaction), 1, tfptr)) {
            if (customer.accountNum == transaction.accountNum) {
                customer.currentBalance += transaction.Amount;
            }
        }
        fwrite(&customer, sizeof(Customer), 1, nfptr);
    }

    // Print newmast.dat content
    rewind(nfptr);
    printf("\n%-10s %-10s %-10s\n", "Acct No", "Name", "Balance");
    printf("-------------------------------------\n");
    while (fread(&customer, sizeof(Customer), 1, nfptr)) {
        if (customer.accountNum != 0) {
            printf("%-10d %-10s %-10.2f\n", customer.accountNum, customer.name, customer.currentBalance);
        }
    }

    fclose(ofptr);
    fclose(tfptr);
    fclose(nfptr);

    return 0;
}
