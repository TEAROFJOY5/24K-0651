#include<stdio.h>
#include<string.h>
typedef struct employee{
    int employeeCode;
    char employeeName[30];
    int day,month,year;
    
}Employee;
void inputEmployeeData(Employee * e){
    printf("Enter Employee Code: \n");
    scanf("%d",&(*e).employeeCode);
    printf("Enter the name of employee: \n");
    scanf(" %[^\n]s",(*e).employeeName);
    printf("Enter the date of joining: \n");
    scanf("%d %d %d",&(*e).day,&(*e).month,&(*e).year);
}
int EmployeeTenure(int day,int month,int year, int currentDay,int currentMonth,int currentYear){
    int tenure=currentYear-year;
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        tenure--;
    }
    return tenure;
}
void tenureDuration(Employee employee[],int size,int currentDay,int currentMonth,int currentYear ){
    printf("Employees having tenure more than 3 years: \n");
    for(int i=0;i<size;i++){
        int tenureTime=EmployeeTenure(employee[i].day,employee[i].month,employee[i].year,currentDay,currentMonth,currentYear);
         if(tenureTime>3){
             printf("Employee Code: %d,Employee Name: %s,Tenure: %d years\n",employee[i].employeeCode,employee[i].employeeName,tenureTime);
         }
    }
    
}
int main(){
    Employee employee[4];
    for(int i=0;i<4;i++){
        printf("\nEnter the details for Employee %d : \n",i+1 );
        inputEmployeeData(&employee[i]);
    }
    int currentDay,currentMonth,currentYear;
    printf("Enter the current date: \n");
    scanf("%d %d %d",&currentDay,&currentMonth,&currentYear);
tenureDuration(employee, 4, currentDay, currentMonth, currentYear);    
 return 0;   
}
    
    
