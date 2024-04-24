/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Kiet Dung Truong
Student ID#:122088230
Email      :kdtruong@myseneca.ca
Section    :ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive (int *intptr)
{
    int value;
    
    // use do-while loop ti continue prompting until a positive value
    do
    {
        // accept user input integer value
        scanf(" %d", &value);
        // if value entered < 0 => Error Message
        if (value <=0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);
    // Way 1: return entered value via pointer arguement
    if (intptr != NULL)
    {
        *intptr = value;
    }
    // Way2: return value
    return value;
    // 2 ways are for practicing, only use 1 in real life
}
//This is the same as the above described getIntPositive function, only this is for a double floating-point type.
double getDoublePositive(double * doubleptr)
{
    double value;
    do
    {
        scanf(" %lf", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);
    if ( doubleptr != NULL)
    {
        * doubleptr = value;
    }
    return value;
}
// 3. opening Message
void openingMessage (const int maxProductNum, const int serve)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProductNum);
    printf("NOTE: A 'serving' is %dg\n",serve);
    return;
}
//4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int prodNum)
{
    struct CatFoodInfo catFoods[maxProduct] = {{0}};
    printf("\nCat Food Product #%d\n", prodNum + 1);
    printf("--------------------\n");
    printf("SKU           : ");
    scanf(" %d", &catFoods[prodNum].prodSkuNum);
    while (catFoods[prodNum].prodSkuNum <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf(" %d", &catFoods[prodNum].prodSkuNum);
    }
    printf("PRICE         : $");
    scanf(" %lf", &catFoods[prodNum].prodPrice);
    while (catFoods[prodNum].prodPrice <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf(" %lf", &catFoods[prodNum].prodPrice);
    }
    printf("WEIGHT (LBS)  : ");
    scanf(" %lf", &catFoods[prodNum].prodWeight);
    while (catFoods[prodNum].prodWeight <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf(" %lf", &catFoods[prodNum].prodWeight);
    }
    printf("CALORIES/SERV.: ");
    scanf(" %d", &catFoods[prodNum].Calories);
    while (catFoods[prodNum].Calories <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf(" %d", &catFoods[prodNum].Calories);
    }
    return catFoods[prodNum];
}
    //5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}
    // 6. Display a formatted record of cat food data
    // void displayCatFoodData (int sku, double *preceptor, int calories, double *weight ); // note => ()

void displayCatFoodData(int prodSkuNum,  double *prodPriceP, int Calories,  double *prodWeightP)
{
    printf("%07d %10.2lf %10.1lf %8d\n", prodSkuNum, *prodPriceP, *prodWeightP, Calories);
    return;
}
    
    // 7. Logic entry point
void start(void)
{
    struct CatFoodInfo catFoods[maxProduct] = {{0}};
    int i;
    openingMessage(maxProduct, gramInServing);
    for (i = 0; i < maxProduct; i++)
    {
        catFoods[i] = getCatFoodInfo(i);
    }
    displayCatFoodHeader();
    for (i = 0; i < maxProduct; i++)
    {
        displayCatFoodData(catFoods[i].prodSkuNum, &catFoods[i].prodPrice, catFoods[i].Calories, &catFoods[i].prodWeight);
    }
}
