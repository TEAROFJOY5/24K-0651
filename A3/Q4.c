#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int* ratings;
    int totalScore;
};

void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            int rating;
            do {
                printf("  Period %d (1-10): ", j + 1);
                scanf("%d", &rating);
                if (rating < 1 || rating > 10) {
                    printf("    Invalid rating! Please enter a value between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            ratings[i][j] = rating;
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    printf("\nEmployee Performance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int bestEmployeeIndex = -1;
    double maxAverage = -1;
    for (int i = 0; i < numEmployees; i++) {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) {
            totalScore += ratings[i][j];
        }
        double averageScore = (double)totalScore / numPeriods;
        if (averageScore > maxAverage) {
            maxAverage = averageScore;
            bestEmployeeIndex = i;
        }
    }
    return bestEmployeeIndex;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int bestPeriodIndex = -1;
    double maxAverage = -1;
    for (int j = 0; j < numPeriods; j++) {
        int totalScore = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalScore += ratings[i][j];
        }
        double averageScore = (double)totalScore / numEmployees;
        if (averageScore > maxAverage) {
            maxAverage = averageScore;
            bestPeriodIndex = j;
        }
    }
    return bestPeriodIndex;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int worstEmployeeIndex = -1;
    double minAverage = 1e9;
    for (int i = 0; i < numEmployees; i++) {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) {
            totalScore += ratings[i][j];
        }
        double averageScore = (double)totalScore / numPeriods;
        if (averageScore < minAverage) {
            minAverage = averageScore;
            worstEmployeeIndex = i;
        }
    }
    return worstEmployeeIndex;
}

int main() {
    int numEmployees, numPeriods;
    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int bestEmployee = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", bestEmployee + 1);

    int bestPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", bestPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
