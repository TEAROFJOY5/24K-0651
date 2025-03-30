#include<stdio.h>
float prd(float a, int b );
int main()
{
    float x=23.44; int z=2;
    float y= prd(x,z);
    printf("%f",y);
}
  float prd(float a, int b)
  {
      float x = a * b;
      return x;
  }
