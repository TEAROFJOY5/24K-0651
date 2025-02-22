//Program that swapped without using a temporary variables.
#include<stdio.h>
int main ()
{
    int a, b;
    printf("\nEnter a and b: ");
    scanf("%d%d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\n%d %d",a,b);
}
