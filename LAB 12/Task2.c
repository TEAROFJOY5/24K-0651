/* Task 2: Write a program to implement the exchange or swap the values of 3 variables{a,b,c}. To
implement this, you need to write a function called swaped().
void swaped(int *aPtr, int *bPtr, int *cPtr);
such that;
b ----> temp
a ----> b
c ----> a
temp ----> a  */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 void swaped(int *aPtr,int *bPtr, int * cPtr ) 
  {
     int temp=*bPtr; 
    *aPtr = *bPtr;   
    *cPtr = *aPtr;     
    *aPtr = temp;
     
  }
    int main()
    {   int *a = (int *)malloc(sizeof(int));
        int *b = (int *)malloc(sizeof(int));
        int *c = (int *)malloc(sizeof(int));
        if( a==NULL || b==NULL || c==NULL){
            printf("\nError in Memory Allocation");
            return 1;
        }

        printf("\nPlease enter a integer number 'a': ");
        scanf("%d",a);
        printf("\nPlease enter a integer number 'b': ");
        scanf("%d",b);
        printf("\nPlease enter a integer number 'c': ");
        scanf("%d",c);      
        printf("\nbefore swaying a=%d, b=%d, c=%d",*a,*b,*c);
        swaped( a, b, c);
        printf("\nAfter swapping: a = %d, b = %d, c = %d\n", *a, *b, *c);
        free(a);
        free(b);
        free(c);

    return 0;
    }
  
