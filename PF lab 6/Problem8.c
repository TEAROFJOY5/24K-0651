#include <stdio.h>

int main() {
    int rows = 5;
    int cols = 5;
    char letters[] = "ABCDEFGHI";
    int letterIndex = 0;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if ((i == 1 && (j == 1 || j == 2 || j == 3)) ||
                (i == 2 && (j == 2 || j == 3)) ||
                (i == 3 && (j == 2 || j == 4)) ||
                (i == 4 && (j == 1 || j == 3 || j == 5)) ||
                (i == 5 && (j == 2 || j == 3 || j == 4))) {
                printf("%c ", letters[letterIndex]);
                letterIndex++;
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
