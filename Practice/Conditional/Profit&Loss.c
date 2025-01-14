/******************************************************************************

             If cost price and selling price of an item is input through the 
keyboard, write a program to determine whether the seller has 
made profit or incurred loss. Also determine how much profit 
he made or loss he incurred. 


*******************************************************************************/

#include <stdio.h>

int main()
{
    int cost_price,selling_price;
    printf("\nEnter the cost price of item: ");
    scanf("%d",&cost_price);
    printf("\nEnter the selling price of item: ");
    scanf("%d",&selling_price);
    if(selling_price>cost_price)
    printf("\nYou have earned a profit on your this deal");
    else if(cost_price>selling_price)
    printf("\nYou have incurred a loss on your this deal");
    else
    printf("\nYour this deal don't leds to a gain or loss.");
}
