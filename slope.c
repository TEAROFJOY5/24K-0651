#include <stdio.h>
int main(void)
{
     int x=(5,4), x1=5, y1=4;
     int y=(3,2), x2=3, y2=2;
     float slope;
     slope = (y2-y1)/(x2-x1);
     printf("The slope of this number is %.3f",slope);
     return 0;
}
