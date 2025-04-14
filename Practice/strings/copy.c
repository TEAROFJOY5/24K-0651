// A program to copy string from a temporary string
#include <stdio.h>
#include<string.h>

 int main()
 {
     int size=0;
     char temp[100];
     printf("\nEnter the string: ");
       fgets(temp,100,stdin);
       temp[strcspn(temp,"\n")] ='\0';
       size=strlen(temp);
      char str [size+1] ;
      strcpy(str,temp);

     printf("\n%d",size);
   
     printf("\n%s",str);
 }
