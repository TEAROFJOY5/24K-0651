/* Write a program to find the factorial value of any number 
 * entered through the keyboard. 
 */
 #include<stdio.h>
 int main()
 {
  int num,fact=1;
  printf("Enter the number: ");
  scanf("%d",&num);
  fact=num;
  for(int i=num;i>1;i--)
  {   
      num--;
      fact*=num;
  }
  printf("\nThe factorial is %d",fact);
 }  
