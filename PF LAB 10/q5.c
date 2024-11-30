#include <stdio.h>

// Function to perform recursive bubble sort
void sortArray(int numbers[], int length) {
    int swapTemp, index;
    if (length == 1) {
        return;
    }
    for (index = 0; index < length - 1; index++) {
        if (numbers[index] > numbers[index + 1]) {
            swapTemp = numbers[index];
            numbers[index] = numbers[index + 1];
            numbers[index + 1] = swapTemp;
        }
    }
    sortArray(numbers, length - 1); // Recursive call
}

// Function to display the elements of an array
void printArray(int numbers[], int length) {
    int index;
    for (index = 0; index < length; index++) {
        printf("%d ", numbers[index]);
    }
    printf("\n");
}

// Main function
int main() {
    int arrayLength, position;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &arrayLength);

    int dataArray[arrayLength];
    printf("Enter %d elements for the array:\n", arrayLength);
    for (position = 0; position < arrayLength; position++) {
        printf("Element %d: ", position + 1);
        scanf("%d", &dataArray[position]);
    }

    printf("\nOriginal array:\n");
    printArray(dataArray, arrayLength);

    sortArray(dataArray, arrayLength); // Sort the array

    printf("\nSorted array:\n");
    printArray(dataArray, arrayLength);

    return 0;
}
