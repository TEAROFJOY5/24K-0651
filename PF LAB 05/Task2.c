#include <stdio.h>

int main() {
    int weekday, vacation;

    // Take user input for weekday and vacation
    printf("Enter 1 for weekday (true) else enter 0 (false): ");
    scanf("%d", &weekday);

    printf("Enter 1 for vacation (true) else enter 0 (false): ");
    scanf("%d", &vacation);

    switch (weekday) {
        case 0: 
            switch (vacation) {
                case 0: 
                    printf("sleepIn(false, false) --> true\n");
                    break;
                case 1: 
                    printf("sleepIn(false, true) --> true\n");
                    break;
                default:
                    printf("Invalid input for vacation.\n");
                    break;
            }
            break;
        case 1: 
       
            switch (vacation) {
                case 0: 
                    printf("sleepIn(true, false) --> false\n");
                    break;
                case 1: 
                    printf("sleepIn(true, true) --> true\n");
                    break;
                default:
                    printf("Invalid input for vacation.\n");
                    break;
            }
            break;
        default:
            printf("Invalid input for weekday.\n");
            break;
    }

    return 0;
}


    
