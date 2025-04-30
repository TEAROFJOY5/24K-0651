#include<stdio.h>
int main()
{
    int arr[2][3] ={{1,2,3},{4,5,6}};
    int (*p)[3];
    
    p = arr;
    
    printf("\nAccessing element using the pointer\n");
    printf("arr[0][0]: %d, arr[0][1]: %d, arr[0][2]: %d\n", (*p)[0], (*p)[1], (*p)[2]);
     printf("arr[1][0]: %d, arr[1][1]: %d, arr[1][2]: %d\n", *(p+1)[0], *(p+1)[1], *(p+1)[2]);

}
