#include <stdio.h>

int main() {
    char expression[100];
    int i = 0, num = 0, result = 0;
    char operator = '+'; 
   
    printf("Enter an expression (e.g., 20+10-30): ");
    scanf("%s", expression);

    while (expression[i] != '\0') {

        if (expression[i] >= '0' && expression[i] <= '9') {
            num = 0; 
            while (expression[i] >= '0' && expression[i] <= '9') {
                num = num * 10 + (expression[i] - '0'); 
                i++;
            }

            if (operator == '+') {
                result += num;
            } else if (operator == '-') {
                result -= num;
            }

            continue; 
        }

        
        if (expression[i] == '+' || expression[i] == '-') {
            operator = expression[i]; 
        } else if (expression[i] == '\0') {
            
            if (operator == '+' || operator == '-') {
                printf("Invalid expression.\n");
                return 0;
            }
            break; 
        }
        i++;
    }

    printf("Result: %d\n", result);
    return 0;
}
