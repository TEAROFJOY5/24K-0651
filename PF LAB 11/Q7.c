#include <stdio.h>

struct Organization {
    char company_name[50];
    int foundation_year;
    char division_names[5][50]; 
};

int main() {
    struct Organization organization;
    int dept_index, loop_index;

    printf("Enter company name: ");
    scanf(" %[^\n]", organization.company_name); 
    printf("Enter year established: ");
    scanf("%d", &organization.foundation_year);
    printf("Enter up to 5 departments (type 'end' to stop):\n");

    for (loop_index = 0; loop_index < 5; loop_index++) {
        printf("Department %d: ", loop_index + 1);
        scanf(" %[^\n]", organization.division_names[loop_index]);
        if (strcmp(organization.division_names[loop_index], "end") == 0) {
            break; 
        }
    }

    printf("\nCompany Details:\n");
    printf("Name: %s\n", organization.company_name);
    printf("Year Established: %d\n", organization.foundation_year);
    printf("Departments:\n");
    
    for (dept_index = 0; dept_index < loop_index; dept_index++) {
        printf("%d. %s\n", dept_index + 1, organization.division_names[dept_index]);
    }

    return 0;
}
