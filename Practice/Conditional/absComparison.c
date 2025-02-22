
#include<stdio.h>
int main ()
{
    int a, b;
    printf("\nEnter a and b: ");
    scanf("%d%d",&a,&b);
    if(a<0 )
    {
        if(b<0)
        {
            if(-a==(-b))
            printf("\n a has same magnitude as b");
            else
            printf("\n a doesnot has same magnitude as b");
        }
        else
        {
            if(-a==b)
            printf("\n a has same magnitude as b");
            else
            printf("\n a doesnot has same magnitude as b");
        }
    }
    else
    {
         if(b<0)
        {
            if(a==(-b))
            printf("\n a has same magnitude as b");
            else
            printf("\n a doesnot has same magnitude as b");
        }
        else
        {
            if(a==b)
            printf("\n a has same magnitude as b");
            else
            printf("\n a doesnot has same magnitude as b");
        }
    }
}
