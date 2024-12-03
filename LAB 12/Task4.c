/*Write a program that ask the user to enter the total 'N' no of characters in user's name {First
Name + Last Name} to create a dynamic array of characters. After create a dynamic array of
that 'N' no of characters using malloc or calloc function. Finally copy your full name in it that has
already been taken from the user before
Dynamic Array = "Muhib Ahmed";*/

#include<stdio.h>
#include<stdlib.h>
int main()
{   int num,i;
    printf("Enter the number of characters in your name(First+Last Name): ");
    scanf("%d",&num);
    
    getchar();
    
    char *ptr=(char *)calloc(num+1,sizeof(char));
     
     if(ptr==NULL)
     {
         printf("Memory Allocation Failed!");
         return 1;
     }
    printf("\nEnter your Full Name: ");

      fgets(ptr,num+1,stdin);  
     printf("Your full name is: %s\n", ptr);
     free(ptr);
}
