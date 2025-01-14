/******************************************************************************

    Find the absolute value of a number entered through the 
keyboard. 

*******************************************************************************/

#include <stdio.h>

int main()
{
    int value,absolute;
    printf("\nEnter the number: ");
    scanf("%d",&value);
    if(value<0)
    {
        absolute=(-(value));
        printf("\nThe absolute value of %d is %d",value,absolute);
    }
    else
    printf("\nThe absolute value of %d is %d",value,value);
    return 0;
}
