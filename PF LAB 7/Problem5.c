#include <stdio.h>

int main() {
    int arr[10];
    int frequency[10] = {0};  
    int i, j;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }


    for (i = 0; i < 10; i++) {
        
        if (frequency[i] == 0) {
            frequency[i] = 1;  
            for (j = i + 1; j < 10; j++) {
                if (arr[i] == arr[j]) {
                    frequency[i]++;  
                    frequency[j] = -1;  
                }
            }
        }
    }

    printf("Element Frequency\n");
    for (i = 0; i < 10; i++) {
        if (frequency[i] > 0) {  
            printf("%d        %d\n", arr[i], frequency[i]);
        }
    }

    return 0;
}
