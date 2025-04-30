
#include <stdio.h>
struct name{
    char firstName[29];
    char lastName[20];
};

struct student{
    struct name studentName;
    char phone[12];
};

int main() {
     struct student s1;
    printf("Enter the first name of the student: ");
    scanf("%28s", s1.studentName.firstName);  // Limit input to avoid overflow

    printf("Enter the last name of the student: ");
    scanf("%19s", s1.studentName.lastName);   // Limit input to avoid overflow

    printf("\nThe name of the student is %s %s\n",
           s1.studentName.firstName, s1.studentName.lastName);
}
