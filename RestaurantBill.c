//Outline:
//First obtain user input for tax and tip percentage.
//Then calculate the new total depending on the meal and display that. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (){
    int a;
    int i; 
    time_t t;
    srand((unsigned) time(&t));
    int random=rand() % 4;
    double taxAmt;
    double tipAmt;
    double taxPercent;
    double tipPercent;
    double meals [4] = {9.95, 4.55, 13.25, 22.35};
    double mealPicked = meals[random];
    
    printf("Please enter a tax percentage: "); 
    scanf("%lf", &taxPercent);
    printf("Please enter a tip percentage: ");
    scanf("%lf", &tipPercent);
    taxAmt = mealPicked*(taxPercent*.01);
    tipAmt = mealPicked*(tipPercent*.01);
    
    double total = mealPicked + taxAmt + tipAmt;
    printf("Meal cost is %.3f\n", mealPicked);
    printf("Total tax amt is %.2f\n", taxAmt);
    printf("Total Tip amt is %.2f\n", tipAmt);
    printf("Total for this transaction is %.2f\n", total);
    
    


}