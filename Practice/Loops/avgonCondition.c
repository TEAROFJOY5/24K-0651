/* Write a program that continuously asks the user for numbers and calculates their average. The loop
 * should terminate when the user enters a negative number.
 */

#include <stdio.h>

int main()
{
    int a,b,avg;
    while(1)
    {
      printf("Enter a and b: ");
      scanf("%d%d",&a,&b);
      if(a<0 || b<0)
      {
          printf("\nThe average cann't be calculated");
          break;
      }
      else
      {
        avg=(a+b)/2;
        printf("\nThe average of %d and %d is %d\n",a,b,avg);
      }    
          
      }
}
