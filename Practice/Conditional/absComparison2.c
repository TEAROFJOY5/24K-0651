#include<stdio.h>
#include<stdlib.h>  // for abs() function

int main() {
    int a, b;
    printf("\nEnter a and b: ");
    scanf("%d%d", &a, &b);

    if (abs(a) == abs(b))  // Compare absolute values
        printf("\n a has same magnitude as b");
    else
        printf("\n a does not have same magnitude as b");

    return 0;
}
