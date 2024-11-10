#include <stdio.h>
#include <string.h>

void sortingStringsByFirstChar(char arr[][50], int n) {
    char temp[50];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][0] > arr[j][0]) {  // Compare the first characters (ASCII values)
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();  // To consume the newline character left by scanf

    char arr[n][50];  // Declare the array of strings with size `n`

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove the newline character
    }

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    sortingStringsByFirstChar(arr, n);  // Call the function to sort the strings

    printf("After sorting based on the first character's ASCII value:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}
