/* Task 1: Write a program that calculates the sum of all the elements in array using pointers
(Note: Generate the array via user)*/


#include<stdio.h>
#include<stdlib.h>
int main()
{   int a,i,sum,*ptr;
    printf("Please enter the number of elements in the array: ");
    scanf("%d",&a);
    ptr=(int *)calloc(a,sizeof(int));
    for(i=0; i<a;i++){
        printf("\nEnter the %d element of the array: ",i+1);
        scanf("%d",ptr+i);
        sum=sum+(*(ptr+i));
     }
     printf("\nThe sum is %d",sum);
     free(ptr);
     
}
