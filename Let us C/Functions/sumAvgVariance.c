#include<stdio.h>
#include<math.h>
 void calculate (int *a,int *b,int *c,int *d,int *e,int *sum,float *avg,float *std_dev )
{
    *sum= *a + *b + *c + *d + *e ;
    *avg=*sum/5.0;
    float variance = ((*a - *avg)*(*a - *avg))+((*b - *avg)*(*b - *avg))+((*c - *avg)*(*c - *avg))+((*d - *avg)*(*d - *avg))+((*e - *avg)*(*e - *avg));
    *std_dev=sqrt(variance);
}
  

    int main()
    {
        int num1, num2, num3, num4,num5;
        int sum;
        float avg, std_dev;
        printf("Enter 5 integers: ");
        scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

        calculate( &num1, &num2, &num3, &num4, &num5, &sum, &avg, &std_dev);

      printf("Sum: %d\n", sum);
      printf("Average: %.2f\n", avg);
      printf("Standard Deviation: %.2f\n", std_dev);

    return 0;

    }
