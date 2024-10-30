#include <stdio.h>

#define SIZE 3

int main() {
    int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE];
    int product[SIZE][SIZE], difference[SIZE][SIZE];

    // Input Matrix A
    printf("Enter elements of matrix A:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("Element [%d][%d]: ", row, col);
            scanf("%d", &matrixA[row][col]);
        }
    }

    // Input Matrix B
    printf("Enter elements of matrix B:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("Element [%d][%d]: ", row, col);
            scanf("%d", &matrixB[row][col]);
        }
    }

    // Multiply matrices A and B
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            product[row][col] = 0; // Initialize the result element
            for (int k = 0; k < SIZE; k++) {
                product[row][col] += matrixA[row][k] * matrixB[k][col];
            }
        }
    }

    // Display the product matrix
    printf("\nProduct of Matrix A and Matrix B:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", product[row][col]);
        }
        printf("\n");
    }

    // Subtract product from Matrix A
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            difference[row][col] = matrixA[row][col] - product[row][col];
        }
    }

    // Display the difference matrix
    printf("\nMatrix A minus the Product Matrix:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", difference[row][col]);
        }
        printf("\n");
    }

    return 0;
}
