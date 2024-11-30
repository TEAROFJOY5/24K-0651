#include <stdio.h>


struct CalendarDate {
    int day;
    int month;
    int year;
};


int checkLeapYear(int givenYear) {
    if ((givenYear % 400 == 0) || (givenYear % 4 == 0 && givenYear % 100 != 0)) {
        return 1;
    }
    return 0;
}


int getDaysInMonth(int currentMonth, int currentYear) {
    if (currentMonth == 1 || currentMonth == 3 || currentMonth == 5 || currentMonth == 7 || 
        currentMonth == 8 || currentMonth == 10 || currentMonth == 12) {
        return 31;
    }
    if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {
        return 30;
    }
    if (currentMonth == 2) {
        return checkLeapYear(currentYear) ? 29 : 28;
    }
    return 0;
}

// Function to check if a date is valid
int validateDate(struct CalendarDate inputDate) {
    if (inputDate.year < 1) return 0;
    if (inputDate.month < 1 || inputDate.month > 12) return 0;
    if (inputDate.day < 1 || inputDate.day > getDaysInMonth(inputDate.month, inputDate.year)) return 0;
    return 1;
}


int calculateDaysDifference(struct CalendarDate startDate, struct CalendarDate endDate) {
    int totalDaysStart = 0, totalDaysEnd = 0, counter;

    for (counter = 1; counter < startDate.year; counter++) {
        totalDaysStart += (checkLeapYear(counter) ? 366 : 365);
    }
    for (counter = 1; counter < startDate.month; counter++) {
        totalDaysStart += getDaysInMonth(counter, startDate.year);
    }
    totalDaysStart += startDate.day;

    for (counter = 1; counter < endDate.year; counter++) {
        totalDaysEnd += (checkLeapYear(counter) ? 366 : 365);
    }
    for (counter = 1; counter < endDate.month; counter++) {
        totalDaysEnd += getDaysInMonth(counter, endDate.year);
    }
    totalDaysEnd += endDate.day;

    return totalDaysEnd - totalDaysStart;
}


const char* findDayOfWeek(struct CalendarDate inputDate) {
    int inputDay = inputDate.day;
    int inputMonth = inputDate.month;
    int inputYear = inputDate.year;

    if (inputMonth <= 2) {
        inputMonth += 12;
        inputYear--;
    }

    int k = inputYear % 100;
    int j = inputYear / 100;
    int calculation = inputDay + (13 * (inputMonth + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    int resultDay = calculation % 7;

    const char* weekDays[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return weekDays[resultDay];
}

// Main function
int main() {
    struct CalendarDate firstDate, secondDate;

    
    printf("Enter the first date (day month year): ");
    scanf("%d %d %d", &firstDate.day, &firstDate.month, &firstDate.year);

   
    printf("Enter the second date (day month year): ");
    scanf("%d %d %d", &secondDate.day, &secondDate.month, &secondDate.year);

  
    if (!validateDate(firstDate)) {
        printf("Invalid first date entered.\n");
        return 0;
    }

  
    if (!validateDate(secondDate)) {
        printf("Invalid second date entered.\n");
        return 0;
    }

  
    int dayDifference = calculateDaysDifference(firstDate, secondDate);
    printf("Number of days between the two dates: %d\n", dayDifference);

    
    printf("Day of the week for the first date: %s\n", findDayOfWeek(firstDate));

    return 0;
}
