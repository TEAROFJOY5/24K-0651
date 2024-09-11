#include <stdio.h>
int main()
{
  float Average_fuel;
  float d=1207;
  float forwardPrice=118;
  float returnPrice=123;
   printf("Enter the car's fuel average");
   scanf("%d",&Average_fuel);
   if (Average_fuel>0){
       float FuelConsumedForward= d/Average_fuel;
       float FuelConsumedReturn=d/Average_fuel;   
       float totalFuelConsumed= FuelConsumedForward + FuelConsumedReturn;
          float CostForward= FuelConsumedForward*forwardPrice;
          float CostReturn= FuelConsumedReturn*returnPrice;   
           float TotalCost= CostForward +CostReturn;
         printf("Total fuel consumed on the trip is %.2f liters",totalFuelConsumed);
         printf("Total cost of the trip is %.2f",TotalCost);
 }    else{ printf("You have enter negative value of car fuel average");}
}          