#include <stdio.h>

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int lastElement = arr[size - 1];


    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Place the last element at the first position
    arr[0] = lastElement;

 
    printf("Shifted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
