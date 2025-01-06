/*If a five-digit number is input through the keyboard, write a 
program to print a new number by adding one to each of its 
digits. For example if the number that is input is 12391 then 
the output should be displayed as 23402. 
*/

#include<stdio.h>
int main()
{
    int new_num, num;
    printf("\nEnter a five digit number:");
    scanf("%d",&num);
     new_num=(((((num / 10000) % 10) + 1) % 10) * 10000) +  // Extract and update 1st digit
              (((((num / 1000) % 10) + 1) % 10) * 1000) +   // Extract and update 2nd digit
              (((((num / 100) % 10) + 1) % 10) * 100) +    // Extract and update 3rd digit
              (((((num / 10) % 10) + 1) % 10) * 10) +     // Extract and update 4th digit
              ((((num % 10) + 1) % 10));                 // Extract and update 5th digit

    printf("\nThe modified string is %d",new_num);
}
