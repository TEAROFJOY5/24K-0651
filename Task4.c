#include<stdio.h>
int main()
{
     float ph;
     printf("Enter pH value:");
     scanf("%f",&ph);
     if (ph>=1 && ph<=14)
     {
	   if (ph==7)
          {   
           printf("Nuetral");
          }
          else if (ph>7)
            {
                 if (ph<12)
                  {
                    printf("\nAlkaline");
                  } else {
                            printf("\nVery Alkaline");
                         }
           }
          else {
                  if (ph>2) {
                        printf("\nVery Acidic");
                            }
                  else {
                   printf("\nAcidic");
                       }
               }
      } else { printf("\nInvalid Input");
    return 0;
}
                     
               
