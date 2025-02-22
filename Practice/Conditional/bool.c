// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>

int main() {
   int a,b,flag;
   printf("\nEnter a and b:");
   scanf("%d%d",&a,&b);
   bool c=a>b;
   if(c)
   {
       flag=1;
   }
   else
   flag=0;
   switch (flag)
   {
       case 1:
       printf("\na is greater than b");
       break;
       case 0:
       printf("\nb is greater than a");
   }

    return 0;
}
