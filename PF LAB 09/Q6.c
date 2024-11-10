#include <stdio.h>

void findMaxMin(int array[], int size, int* maxValue, int* minValue) {
    *maxValue = array[0];
    *minValue = array[0];
    
    for (int i = 1; i < size; i++) {
        if (array[i] > *maxValue) {
            *maxValue = array[i];  // Update maximum value
        }
        if (array[i] < *minValue) {
            *minValue = array[i];  // Update minimum value
        }
    }
}

int main() {
    int arraySize;
    
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);  // Get the size of the array
    
    int array[arraySize];  // Declare the array with the entered size
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);  // Get each element of the array
    }
    
    int max, min;
    
    findMaxMin(array, arraySize, &max, &min);  // Call the function to find max and min values
    
    printf("The maximum value in the array is: %d\n", max);
    printf("The minimum value in the array is: %d\n", min);
    
    return 0;
}
