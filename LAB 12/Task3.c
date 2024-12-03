/* Write a C Program to Find Largest Number in an array Using Dynamic Memory Allocation. Note:
The array must be dynamically resized and initially the array size will be taken by the user and
then resized by the user
Example arr[5]={1,2,3,4,5}
//After resizing
Arr[7]={1,2,3,4,5,6,7}
Take the same array and resize it. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, i, n, *ptr, largest;

   
    printf("Please enter the number of elements in the array: ");
    scanf("%d", &a);

    
    ptr = (int *)calloc(a, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    for (i = 0; i < a; i++) {
        printf("\nEnter the %d element of the array: ", i + 1);
        scanf("%d", (ptr + i));
    }

    
    largest = *(ptr + 0); 
    
    for (i = 0; i < a; i++) {
        if (largest < *(ptr + i)) {
            largest = *(ptr + i);
        }
    }
    printf("Largest element of the array is %d\n", largest);

   
    printf("\nEnter the new size of the array: ");
    scanf("%d", &n);

    
    ptr = (int *)realloc(ptr, n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    
    if (n > a) {
        for (i = a; i < n; i++) {
            printf("\nEnter the %d element of the resized array: ", i + 1);
            scanf("%d", (ptr + i));
        }
    }

 
    printf("The new array is: {");
    for (i = 0; i < n; i++) {
        printf("%d", *(ptr + i));
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");


    free(ptr);

    return 0;
}
