/******************************************************************************

             If the ages of Ram, Shyam and Ajay are input through the 
keyboard, write a program to determine the youngest of the 
three

*******************************************************************************/

#include <stdio.h>

int main()
{
    int R_age,S_age,A_age;
    char ch;
    
    printf("\nEnter the age of Ram: ");
      /* get() is used to read each character of the input.
   We then convert the characters (which are digits) into an integer 
   by multiplying the previous number by 10 and adding the current digit.
   The loop continues until a newline character (\n) is encountered, 
   indicating the end of the input. And characters inputted are converted into the form of an integer number.
  */
    while ((ch = getc(stdin)) != '\n') {
        if (ch >= '0' && ch <= '9') {
            R_age = R_age * 10 + (ch - '0');
        }
    }
   // printf("\nThe age of Ram is %d",R_age);
   
   printf("\nEnter the age of Shyam: "); 
 
    while ((ch = getc(stdin)) != '\n') {
        if (ch >= '0' && ch <= '9') {
            S_age = S_age * 10 + (ch - '0');
        }
    }
    
    printf("\nEnter the age of Ajay: ");
    while ((ch = getc(stdin)) != '\n') {
        if (ch >= '0' && ch <= '9') {
            A_age = A_age * 10 + (ch - '0');
        }
    }
   if (R_age < S_age && R_age < A_age) {
        printf("Ram is the youngest.\n");
    } else if (S_age < R_age && S_age < A_age) {
        printf("Shyam is the youngest.\n");
    } else if (A_age < R_age && A_age < S_age) {
        printf("Ajay is the youngest.\n");
    } else if (R_age == S_age && R_age < A_age) {
        printf("Ram and Shyam are the youngest.\n");
    } else if (R_age == A_age && R_age < S_age) {
        printf("Ram and Ajay are the youngest.\n");
    } else if (S_age == A_age && S_age < R_age) {
        printf("Shyam and Ajay are the youngest.\n");
    } else {
        printf("All three have the same age.\n");
    }
    return 0;
}
