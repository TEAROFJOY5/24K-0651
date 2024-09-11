#include <stdio.h>
int main(void)
{
	int pay, payment;
	int Salary;
	float tax;
	printf("Enter the salary of the employee:");
	scanf("%d",&pay);
	printf("Enter the percentage of total taxes:");
	scanf("%f",&tax);
	payment=(tax/100)*pay;
	Salary= pay- payment;
	printf("The total salary is %d",Salary);
}