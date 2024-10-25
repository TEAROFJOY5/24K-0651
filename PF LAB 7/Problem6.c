#include <stdio.h>

int main() {
    int size = 5;
    int arr[5];
    int count[5] = {0}; 

    printf("Array Size = %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > 1) {
            printf("Number %d occurs more than once.\n", arr[i]);
            return 0; 
        }
    }

    printf("No duplicates found.\n");
    return 0;
}
