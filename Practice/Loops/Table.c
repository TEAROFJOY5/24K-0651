/* Write a program to print the multiplication table of the 
 *number entered by the user. The table should get displayed in 
* the following form. 
 * 29 * 1 = 29 
 * 29 * 2 = 58
 */
 #include<stdio.h>

int main() {
    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    for(int i=0;i<10;i++)
    {   int prod=num*(i+1);
        printf("\n%d * %d = %d",num,i+1,prod);
    }
  return 0;
}
