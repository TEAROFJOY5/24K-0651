#include <stdio.h>

struct Location {
    char city_name[50];
    char postal_code[20];
};

struct Worker {
    char full_name[50];
    int employee_id;
    float monthly_salary;
    struct Location location;
};

int main() {
    int num_employees, index;
    FILE *file_pointer;

    printf("Enter number of employees: ");
    scanf("%d", &num_employees);

    struct Worker employee_data[num_employees];

    for (index = 0; index < num_employees; index++) {
        printf("\nEnter details for employee %d:\n", index + 1);
        printf("Name: ");
        scanf(" %[^\n]", employee_data[index].full_name);
        printf("ID: ");
        scanf("%d", &employee_data[index].employee_id);
        printf("Salary: ");
        scanf("%f", &employee_data[index].monthly_salary);
        printf("City: ");
        scanf(" %[^\n]", employee_data[index].location.city_name);
        printf("Zip Code: ");
        scanf(" %[^\n]", employee_data[index].location.postal_code);
    }

    file_pointer = fopen("employees.dat", "wb");
    if (file_pointer == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fwrite(employee_data, sizeof(struct Worker), num_employees, file_pointer);
    fclose(file_pointer);

    printf("Employee data saved to file\n");

    file_pointer = fopen("employees.dat", "rb");
    if (file_pointer == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nEmployee Details:\n");
    while (fread(&employee_data[0], sizeof(struct Worker), 1, file_pointer)) {
        for (index = 0; index < num_employees; index++) {
            printf("\nName: %s\n", employee_data[index].full_name);
            printf("ID: %d\n", employee_data[index].employee_id);
            printf("Salary: %.2f\n", employee_data[index].monthly_salary);
            printf("City: %s\n", employee_data[index].location.city_name);
            printf("Zip Code: %s\n", employee_data[index].location.postal_code);
        }
    }
    fclose(file_pointer);
    return 0;
}
