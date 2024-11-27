#include <stdio.h>

struct SubjectMarks {
    int mathematics;
    int science;
    int english;
};

struct StudentRecord {
    int student_id;
    char student_name[50];
    struct SubjectMarks subject_marks;
};

int main() {
    struct StudentRecord student_list[5];
    int student_index;
    float average_marks;

    // Input details for each student
    for (student_index = 0; student_index < 5; student_index++) {
        printf("Enter details for student %d:\n", student_index + 1);
        printf("Student ID: ");
        scanf("%d", &student_list[student_index].student_id);
        printf("Student Name: ");
        scanf(" %[^\n]", student_list[student_index].student_name); // Read string with spaces
        printf("Marks in Mathematics: ");
        scanf("%d", &student_list[student_index].subject_marks.mathematics);
        printf("Marks in Science: ");
        scanf("%d", &student_list[student_index].subject_marks.science);
        printf("Marks in English: ");
        scanf("%d", &student_list[student_index].subject_marks.english);
        printf("\n");
    }

    // Display average marks for each student
    printf("Average marks for each student:\n");
    for (student_index = 0; student_index < 5; student_index++) {
        average_marks = (student_list[student_index].subject_marks.mathematics +
                         student_list[student_index].subject_marks.science +
                         student_list[student_index].subject_marks.english) / 3.0;
        printf("Student %d (%s): %.2f\n",
               student_list[student_index].student_id,
               student_list[student_index].student_name,
               average_marks);
    }

    return 0;
}
