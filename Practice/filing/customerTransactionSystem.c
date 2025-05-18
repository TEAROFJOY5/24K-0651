#include<stdio.h>
typedef struct customerData{
    int accountNum;
    char name[8];
    float currentBalance;
}Customer;

typedef struct transactionData{
   int accountNum;
   float Amount; 
}Transaction;

int main()
{
    Customer customer;
    FILE *ofptr;
    ofptr=fopen("oldmast.dat","rb+");
    if(!ofptr)
    {
         ofptr=fopen("oldmast.dat","wb+");
         if(ofptr)
         {
             Customer customer = {0, "\0", 0.0};  // ✅ Right way

             for(int i=0; i<100; i++)
             {
                 fwrite(&customer, sizeof(Customer),1,ofptr );  //Creating 100 blank custome data.
             }
         }
    
        else {
            printf("File creation failed!: ");
            return 0;
        }
    }
    printf("Creating oldmast.dat (master file)...\n");

    printf("\nEnter account number (1 to 100), 0 to end the input: ");
     scanf("%d",&customer.accountNum);
     while(customer.accountNum != 0 && customer.accountNum <=100)
    
    {
        printf("\nEnter customer name and their balance: ");
        scanf("%s %f", customer.name, &customer.currentBalance);

        fseek(ofptr, (customer.accountNum-1)*sizeof(Customer),SEEK_SET);
        fwrite(&customer,sizeof(Customer),1,ofptr);
        printf("\nEnter account number (1 to 100), 0 to end the input: ");
        scanf("%d",&customer.accountNum);
    }
    fclose(ofptr);
     Transaction transaction;
    FILE *tfptr;
    tfptr=fopen("trans.dat","rb+");
    if(!tfptr)
    {
         tfptr=fopen("trans.dat","wb+");
         if(tfptr)
         {
             Transaction transaction = {0, 0.0};  // ✅ Right way

             for(int i=0; i<100; i++)
             {
                 fwrite(&transaction, sizeof(Transaction),1,tfptr );  //Creating 100 blank Transaction data.
             }
         }
    
        else {
            printf("File creation failed!: ");
            return 0;
        }
    }
   printf("Creating trans.dat (transaction file)...\n");

    printf("\nEnter account number (1 to 100), 0 to end the input: ");
   scanf("%d",&transaction.accountNum);
   while(transaction.accountNum != 0 && transaction.accountNum <=100)
    {
        printf("\nEnter transaction ammount: ");
        scanf("%f",&transaction.Amount);
        fseek(tfptr, (transaction.accountNum-1)*sizeof(Transaction),SEEK_SET);
        fwrite(&transaction,sizeof(Transaction),1,tfptr);
        printf("\nEnter account number (1 to 100), 0 to end the input: ");
        scanf("%d",&transaction.accountNum);
    }
    fclose(tfptr);
    ofptr=fopen("oldmast.dat","rb");
    tfptr=fopen("trans.dat","rb");
    FILE *nfptr;
    nfptr= fopen("newmast.dat","wb+");
    if(!nfptr)
    {
        printf("\nFail openning failed!");
        return 1;
    }
    rewind(ofptr);  // Ensure master file is at the start
   while (fread(&customer, sizeof(Customer), 1, ofptr)) {
    rewind(tfptr);  // Start transaction file again for each customer

    while (fread(&transaction, sizeof(Transaction), 1, tfptr)) {
        if (customer.accountNum == transaction.accountNum) {
            customer.currentBalance += transaction.Amount;
        }
    }

    // Write updated customer record to newmast.dat
    fwrite(&customer, sizeof(Customer), 1, nfptr);
    // Now reading from newmast.dat and then printing the content to the coneole.
    rewind(nfptr);  // Move to the beginning of newmast.dat

    printf("\n%-10s %-10s %-10s\n", "Acct No", "Name", "Balance");
    printf("-------------------------------------\n");

    while (fread(&customer, sizeof(Customer), 1, nfptr)) {
    if (customer.accountNum != 0) {  // Skip blank records
        printf("%-10d %-10s %-10.2f\n", customer.accountNum, customer.name, customer.currentBalance);
    }
}

}
    fclose(ofptr);
    fclose(tfptr);
    fclose(nfptr);

}
