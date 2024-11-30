#include <stdio.h>

// Function to recursively print the elements of an array
void displayArray(int numbers[], int length, int currentIndex) {
    if (currentIndex == length) {
        return;
    }
    printf("%d ", numbers[currentIndex]);
    displayArray(numbers, length, currentIndex + 1);
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int values[size];
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("The elements in the array are: ");
    displayArray(values, size, 0);
    
    return 0;
}
