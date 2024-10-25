#include <stdio.h>

int main() {
    float gpa;
    printf("Enter GPA: ");
    scanf("%f", &gpa);

    (gpa >= 0.00 && gpa <= 0.99) ? printf("\nFailed semester - registration suspended") :
    (gpa >= 1.00 && gpa <= 1.99) ? printf("\nOn probation for next semester") :
    (gpa >= 2.00 && gpa <= 2.99) ? printf("\nRegular standing") :
    (gpa >= 3.00 && gpa <= 3.49) ? printf("\nDean's list for semester") :
    (gpa >= 3.50 && gpa <= 4.00) ? printf("\nHighest honors for semester") :
    printf("\nInvalid input");

    return 0;
}
