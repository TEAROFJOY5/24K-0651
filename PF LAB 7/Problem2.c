#include <stdio.h>

int main() {
    char str[50];
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    int j = 0;

  
    printf("Enter a string: ");
    

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[j] = ch;
        j++;
    }
    str[j] = '\0';  // Null-terminate the string

    // Count vowels
    for (j = 0; str[j] != '\0'; j++) {
        switch (str[j]) {
            case 'a': case 'A':
                a++;
                break;
            case 'e': case 'E':
                e++;
                break;
            case 'i': case 'I':
                i++;
                break;
            case 'o': case 'O':
                o++;
                break;
            case 'u': case 'U':
                u++;
                break;
        }
    }

    // Print the frequency of each vowel
    printf("a=%d, e=%d, i=%d, o=%d, u=%d\n", a, e, i, o, u);

    return 0;
}
