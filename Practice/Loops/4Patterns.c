
#include<stdio.h>
int main()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    puts("");
    puts("");
     for(int i=10; i>0; i--)
    {
        for(int j=i; j>0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
    puts("");
    puts("");
    // 3rd Pattern of asterisks
    // Inverted Right alligned triangle
     for (int i = 0; i < 10; i++) {
        // Print leading spaces
        for (int space = 0; space < i; space++) {
            printf(" ");
        }

        // Print stars
        for (int j = 0; j < 10 - i; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
    puts("");
    puts("");
      //4th Pattern of asterisks
      // Right alligned triangle
      for (int i = 1; i <= 10; i++) {
        // Print spaces first
        for (int space = 1; space <= 10 - i; space++) {
            printf(" ");
        }

        // Then print stars
        for (int star = 1; star <= i; star++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}
