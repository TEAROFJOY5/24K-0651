#include<stdio.h>
int main()
{
    int b = 0, u; // Initialize b and u
    printf("\nEnter the total number of units: ");
    scanf("%d", &u);
    
    // Calculate bill based on unit slabs
    if (0 <= u && u <= 99)
    {
        b = u * 155; // For 0 to 99 units
    }
    else if (100 <= u && u <= 199)
    {
        b = (u - 100) * 200 + 99 * 155; // For 100 to 199 units
    }
    else if (u >= 200)
    {
        b = 99 * 155 + 100 * 200 + (u - 200) * 300; // For 200 and above units
    }

    printf("\nYour bill for %d units is %d\n", u, b);
    return 0;
}
