/* A program that caculate string length,
* that copy strings, 
* that compare strings,
* and that catenate one string into another
* using the custom made functions. 
*/



#include<stdio.h>
int xstrlen(char str1[])
{   int length=0;
    for(int i=0;str1[i]!='\0';i++)
    {
        length++;
    }  return length;
}  

char xstrcpy(char str2[],const char str1[])
{   int i=0;
    while (str1[i]!='\0')
    {
        str2[i]=str1[i];
        i++;
    }
    str2[i]='\0';
    return *str2;
}
     char* xstrcat(char str1[], const char str2[]) {
    int i = 0; // Index for str1
    int j = 0; // Index for str2

    // Move i to the end of str1
    while (str1[i] != '\0') {
        i++;
    }

    // Copy characters from str2 to the end of str1
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    // Null-terminate the resulting string
    str1[i] = '\0';

    return str1;
}
int xstrcmp(const char str1[], const char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

int main()
{
    char str1[]="Hello";
    char str2[19],str3[20],str4[20];
    int length= xstrlen(str1);
    xstrcpy(str2,str1);
    printf("\nthe length of string 1 is %d",length);
    printf("\nString 2 is %s",str2);
    printf("\nAfter catenation %s",xstrcat(str2,str1));
     printf("\nEnter a string: ");
     scanf("%s",str3);
      printf("\nEnter a string: ");
     scanf("%s",str4);
     int result = xstrcmp(str3, str4);

    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("\"%s\" is less than \"%s\".\n", str1, str2);
    } else {
        printf("\"%s\" is greater than \"%s\".\n", str1, str2);
    }
}    
