#include<stdio.h>
int main()
{
 int n;
 printf("Enter a number:");
 scanf("%d",&n);
  (n%10==0)? printf("\nLast digit is zero"): printf("\nLast digit is non-zero");
}
