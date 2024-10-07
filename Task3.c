#include<stdio.h>
int main ()
{
 float t=0.0;
 char c,s;
  printf("Enter w for white coffee or b for black coffee:");
  scanf("%c",&c);
    getchar();
  printf("\nEnter 's' for small,'m' for medium, and 'l' for large size:");
  scanf("%c",&s);
  switch (c)
   {
     case 'w': case 'W':
       switch (s)
        {
            t=5.0;
           case 's': 
            case 'S':
             printf("\n236 ml");
	        break;
           case 'm':
           case 'M':
            t+=t*.15;
             printf("\n355 ml");
                break;
           case 'l': 
            case 'L':
              t+=t*25;
             printf("\n475 ml");
             break;
       
         
        default :
          printf("\nYou have entered invalid size"); 
         }

          printf("\nBaking time :%.1f min", t);
        printf("\nIngredients: \nWater \nCoffee Grounds \nCreamer \nSugar");
         break;
       
         case 'b': case 'B':
             switch (s)
        {
             t=5.0;
           case 's':
          case 'S':
             printf("\n236 ml");
	        break;
           case 'm': 
           case 'M':
            t+=t*.15;
             printf("\n355 ml");
                break;
           case 'l' : 
           case 'L':
              t+=t*25;
             printf("\n475 ml");
             break;
        
        default :
          printf("\nYou have entered invalid size");
        
         }
        printf("\nBaking time :%.1f min", t);
        printf("\nIngredients: \nWater \nCoffee Grounds \nCreamer \nSugar");
         break;
      default:
         printf("\nYou have entered wrong coffee type");
 }
}              
