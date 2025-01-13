/******************************************************************************

             Write a program to fill the entire screen with diamond and 
heart alternatively. The ASCII value for heart is 3 and that of 
diamond is 4.

*******************************************************************************/

#include <stdio.h>

int main()
{
   int rows=25;
   int cols=80;
   for(int i=0;i<rows;i++){
       for(int j=0;j<cols;j++){
           if ((i + j) % 2 == 0) {
                printf("%c", 3); // Print heart (ASCII 3)
            } else {
                printf("%c", 4); // Print diamond (ASCII 4)
            }
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}

/* (if ascii code is not working in the compiler, use the following code that is working on unicode.)
  #include <stdio.h>

int main() {
    int rows = 25;  // Adjust based on terminal size
    int cols = 80;  // Adjust based on terminal size

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                printf("\u2665"); // Unicode heart
            } else {
                printf("\u2666"); // Unicode diamond
            }
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}
*/


