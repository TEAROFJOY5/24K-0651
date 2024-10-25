#include <stdio.h>

int main() {
    char str[50], reversed[50];
    int length = 0, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);  

    while (str[length] != '\0') {
        length++;
    }

    // Reverse the string
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';  // Null-terminate the reversed string

    // Check if the original string is the same as the reversed string
    for (int i = 0; i < length; i++) {
        if (str[i] != reversed[i]) {
            isPalindrome = 0;
            break;
        }
    }

    
    if (isPalindrome) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
