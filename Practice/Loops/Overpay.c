/* Write a program to calculate overtime pay of 10 employees. 
 * overtime pay of 10 employees. 
 * Overtime is paid at the rate of Rs. 12.00 per hour for every 
 * hour worked above 40 hours. Assume that employees do not 
 * work for fractional part of an hour. 
 */ 
#include <stdio.h>

int main() {
    int hrs=0,over_hrs=0;
    float overtime_pay=0;
    for(int i=0;i<10;i++)
    {
        printf("\nEnter the number of hours worked by %d employee: ",i+1);
        scanf("%d",&hrs);
        if(hrs>40)
        {
         over_hrs=hrs-40;
         overtime_pay=over_hrs*12.00;
           printf("\nThe overtime pay of %d employee is %f",i+1,overtime_pay);
        }
        else
        {
         over_hrs=0;
           printf("\nTheir is no overtime pay for %d employee",i+1);
        } 
        
   
       
    }
    
    return 0;
}
