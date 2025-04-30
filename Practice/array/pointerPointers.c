#include<stdio.h>

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // Pointer to an array of 3 integers (each row of the 2D array)
    int (*p)[3];
    p = arr;  // p points to the first row of arr

    // Pointer to a pointer to an integer
    int *p1 = (int *)arr;  // Treat arr as a pointer to int (1D array)
    int **ptr = &p1;  // ptr points to p1
    
    // Accessing elements using pointer to array (p)
    printf("\nAccessing element using pointer to array:\n");
    printf("arr[0][0]: %d, arr[0][1]: %d, arr[0][2]: %d\n", (*p)[0], (*p)[1], (*p)[2]);
    printf("arr[1][0]: %d, arr[1][1]: %d, arr[1][2]: %d\n", (*(p + 1))[0], (*(p + 1))[1], (*(p + 1))[2]);

    // Accessing elements using pointer to pointer (ptr)
    printf("\nAccessing element using pointer to pointer:\n");
    printf("arr[0][0]: %d, arr[0][1]: %d, arr[0][2]: %d\n", *(*(ptr))[0], *(*(ptr))[1], *(*(ptr))[2]);
    printf("arr[1][0]: %d, arr[1][1]: %d, arr[1][2]: %d\n", *(*(ptr + 3))[0], *(*(ptr + 3))[1], *(*(ptr + 3))[2]);

    return 0;
}
