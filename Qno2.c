#include<stdio.h>

int main(void)
{
  int a,b;
  printf("Enter the first number: \n");
  scanf("%d",&a);
  printf("Enter the Second number: \n");
  scanf("%d",&b);
  a=a+b;     
  b=a-b;         //This is where swapping happen.
  a=a-b;
  printf("The First number=%d \n",a);
  printf("The Second number=%d \n",b);
}