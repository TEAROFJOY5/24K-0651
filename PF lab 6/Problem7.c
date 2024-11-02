#include <stdio.h>
int main (){
    int i;
    int n=5;
    char ch;
    for (i=0;i<n*n;i++)
    {
        int row=i/n;
        int col=i%n;
        ch='A'+row;
        if (row==0 || row==n-1 || col==0 || col==n-1)
          printf("%c ",ch+col);
          else
          printf("  ");
          if (col==n-1)
          printf("\n");
         
    }
    }
