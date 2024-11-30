#include <stdio.h>
#define MAX_ALLOWED_TEMP 50.0

void analyzeTemperature(float currentTemp) {
    static int exceedCount = 0; // Keeps track of exceedances across all function calls
    if (currentTemp > MAX_ALLOWED_TEMP) {
        exceedCount++;
        printf("Temperature %.2f°C exceeds the maximum allowable limit of %.2f°C.\n", currentTemp, MAX_ALLOWED_TEMP);
    } else {
        printf("Temperature %.2f°C is within the allowable limit.\n", currentTemp);
    }
    printf("Number of times temperatures exceeded the limit: %d\n", exceedCount);
}

int main() {
    float inputTemp;
    char userChoice;
    do {
        printf("Enter a temperature in Celsius: ");
        scanf("%f", &inputTemp);

        analyzeTemperature(inputTemp);

        printf("Do you want to enter another temperature? (y/n): ");
        scanf(" %c", &userChoice);
    } while (userChoice == 'y' || userChoice == 'Y');

    return 0;
}
