#include<stdio.h>
int main( ) 
{ 
  int   num, i, isPrime=1 ; 
  printf ( "Enter a number " ) ; 
  scanf ( "%d", &num ) ; 
   i = 2 ; 
 while ( i <= num - 1 ) 
   { 
      if ( num % i == 0 ) 
       {
          isPrime=0;
         printf ( "Not a prime number" ) ; 
         break;
       }
  i++ ; 
   }
   // Check the value of isPrime
  if (isPrime == 1 && num > 1)
    printf("The number is a prime number\n");
  return 0;
}
