/******************************************************************************

           Write a program to produce the following output: 
A B C D E F G F E D C B A
A B C D E F   F E D C B A
A B C D E       E D C B A
A B C D           D C B A
A B C               C B A
A B                   B A
A                       A
*******************************************************************************/

#include <stdio.h>

int main() {
    int i, j, k;

    for (i = 7; i >= 1; i--) {
        // Print the increasing sequence
        for (j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }
        // Print spaces
        for (k = 1; k <= 2 * (7 - i); k++) {
            printf(" ");
        }
        // Print the decreasing sequence
        for (j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }

    return 0;
}
