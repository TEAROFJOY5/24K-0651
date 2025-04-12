#include<stdio.h>
#define STUDENTS 5
#define SUBJECTS 6

int main() {
    int result[STUDENTS * SUBJECTS]; // One-dimensional array to store all marks
    int frequency[11] = {0}; // Frequency array for marks 1-10 (index 0 is unused)

    printf("\nEnter the marks of 6 subjects for 5 students (marks should be from 1-10): ");

    // Input the marks for each student
    for (int i = 0; i < STUDENTS; i++) {
        printf("\nEnter the marks of student %d:\n", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            // Calculate the correct index for this student and subject
            scanf("%d", &result[i * SUBJECTS + j]);

            // Check if the mark is between 1 and 10, else ask again
            if (result[i * SUBJECTS + j] < 1 || result[i * SUBJECTS + j] > 10) {
                printf("Invalid input! Marks should be between 1 and 10. Please re-enter the mark for subject %d: ", j + 1);
                j--; // Stay on the same subject if input is invalid
            }
        }
    }

    // Calculate frequency of each mark (1 to 10)
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < SUBJECTS; j++) {
            frequency[result[i * SUBJECTS + j]]++;
        }
    }

    // Print the frequency of each mark
    printf("\nFrequency of marks (1-10):\n");
    for (int i = 1; i <= 10; i++) {
        printf("Mark %d: %d\n", i, frequency[i]);
    }

    return 0;
}
