#include<stdio.h>

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // Pointer to an array of 3 integers (each row of the 2D array)
    int (*p)[3];
    p = arr;  // p points to the first row of arr

    // Pointer to the first element of the array (treating the whole 2D array as 1D array)
    int *p1 = (int *)arr;  // Treat arr as a pointer to int (1D array)
    
    // Accessing elements using pointer to array (p)
    printf("\nAccessing element using pointer to array:\n");
    printf("arr[0][0]: %d, arr[0][1]: %d, arr[0][2]: %d\n", (*p)[0], (*p)[1], (*p)[2]);
    printf("arr[1][0]: %d, arr[1][1]: %d, arr[1][2]: %d\n", (*(p + 1))[0], (*(p + 1))[1], (*(p + 1))[2]);

    // Accessing elements using pointer to pointer (p1 as base address of arr)
    printf("\nAccessing element using pointer to pointer:\n");
    // Since p1 is a pointer to the first element (treating arr as a linear array), we can use it.
    printf("arr[0][0]: %d, arr[0][1]: %d, arr[0][2]: %d\n", *(p1), *(p1+1), *(p1+2));
    printf("arr[1][0]: %d, arr[1][1]: %d, arr[1][2]: %d\n", *(p1+3), *(p1+4), *(p1+5));

    return 0;
}
