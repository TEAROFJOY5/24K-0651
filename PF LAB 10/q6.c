#include <stdio.h>
#include <string.h>

// Struct for Travel Details
struct TourDetails {
    char tripName[50];
    char location[50];
    int tripDays;
    float tripCost;
    int seatsAvailable;
};

// Function to display all travel packages
void showTourOptions(struct TourDetails trips[], int totalTrips) {
    int index;
    printf("\nAvailable Tour Packages:\n");
    for (index = 0; index < totalTrips; index++) {
        printf("%d. Package Name: %s\n", index + 1, trips[index].tripName);
        printf("   Location: %s\n", trips[index].location);
        printf("   Duration: %d days\n", trips[index].tripDays);
        printf("   Cost: $%.2f\n", trips[index].tripCost);
        printf("   Seats Available: %d\n", trips[index].seatsAvailable);
        printf("\n");
    }
}

// Function to handle booking of a travel package
void reserveTour(struct TourDetails trips[], int totalTrips) {
    int selection, requestedSeats;
    showTourOptions(trips, totalTrips);
    printf("Enter the number of the package you want to book: ");
    scanf("%d", &selection);

    if (selection < 1 || selection > totalTrips) {
        printf("Invalid choice! Please try again.\n");
        return;
    }

    if (trips[selection - 1].seatsAvailable == 0) {
        printf("Sorry, no seats are available for this package.\n");
        return;
    }

    printf("Enter the number of seats you want to book: ");
    scanf("%d", &requestedSeats);

    if (requestedSeats > trips[selection - 1].seatsAvailable) {
        printf("Sorry, only %d seats are available. Please try again.\n", trips[selection - 1].seatsAvailable);
        return;
    }

    trips[selection - 1].seatsAvailable -= requestedSeats;
    printf("You have successfully booked %d seat(s) for the package '%s'.\n",
           requestedSeats, trips[selection - 1].tripName);
}

// Main function
int main() {
    struct TourDetails tours[3] = {
        {"Explore Paris", "Paris", 7, 1500.00, 10},
        {"Hawaiian Beach Escape", "Hawaii", 5, 1200.00, 5},
        {"Mountain Adventure", "Mount Everest", 10, 2500.00, 2}
    };

    int userChoice;

    while (1) {
        printf("\nTravel Booking Portal\n");
        printf("1. View Available Tours\n");
        printf("2. Book a Tour\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 1) {
            showTourOptions(tours, 3);
        } else if (userChoice == 2) {
            reserveTour(tours, 3);
        } else if (userChoice == 3) {
            printf("Thank you for using the Travel Booking Portal. Goodbye!\n");
            return 0;
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}
