#include <stdio.h>
int main(){
        float calc,P,R,T;
        printf("Enter the principal value from 100 to 1000000 Rs.");
        scanf("%f",&P);
        printf("Enter the rate of interest from 5 to 10\n: ");
        scanf("%f",&R);
        printf("Enter the time from 1 to 10 years\n:");
	scanf("%f",&T);
      calc= (P*R*T)/100;
      printf("The simple interest is %f",calc); 
      return 0;
}
