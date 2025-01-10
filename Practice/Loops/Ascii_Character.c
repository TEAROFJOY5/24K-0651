/* Write a program to print all the ASCII values and their 
 * equivalent characters using a while loop. The ASCII values 
 * vary from 0 to 255.
 */
 #include<stdio.h>
 int main()
 {
   int ascii=0;
    printf("ASCII Value   Character\n");
    printf("------------------------\n");
   while(ascii<=255)
   {
       printf("%3d        %c\n", ascii, ascii);
       ascii++;
   }
   return 0;
 }  
