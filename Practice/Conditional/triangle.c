/******************************************************************************

    Write a program to check whether a triangle is valid or not, 
    when the three angles of the triangle are entered through the 
    keyboard. A triangle is valid if the sum of all the three angles 
    is equal to 180 degrees. 

*******************************************************************************/

#include <stdio.h>

int main()
{
    int A1,A2,A3;
    printf("\nEnter the 1st angle:");
    scanf("%d",&A1);
    printf("\nEnter the 2nd angle:");
    scanf("%d",&A2);
    printf("\nEnter the 3rd angle:");
    scanf("%d",&A3);
    if((A1+A2+A3)==180)
    printf("\nThe entered angles are the angles of an valid triangle.");
    else
    printf("\nThe entered angles are not the angles of an valid triangle.\nUnvalid triangle.");
    return 0;
}
