#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* x)
{
    int value;
    scanf("%d", &value);
    while (value <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%d", &value);
    }
    if (x != NULL)
        *x = value;
    return value;
}

double getDoublePositive(double* x)
{
    double value;
    scanf("%lf", &value);
    while (value <= 0)
    {
        printf("ERROR: Enter a positive value: ");
        scanf("%lf", &value);
    }
    if (x != NULL)
        *x = value;
    return value;
}

void openingMessage(const int numProducts)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
    printf("NOTE: A 'serving' is %dg\n", GRAMS);

}

CatFoodInfo getCatFoodInfo(const int seqenceNum)
{
    CatFoodInfo prod = { 0 };
    printf("\nCat Food Product #%d\n""--------------------\n", seqenceNum);
    printf("SKU           : ");
    getIntPositive(&prod.sku);
    printf("PRICE         : $");
    getDoublePositive(&prod.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&prod.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&prod.calories);
    return prod;
}

void displayCatFoodHeader(void)
{
    printf("\n");
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo cat[MAX_NO_OF_PRODUCTS];
    int i;
    openingMessage(MAX_NO_OF_PRODUCTS);
    for (i = 0; i < MAX_NO_OF_PRODUCTS; i++)
    {
        cat[i] = getCatFoodInfo(i);
    }
    printf("\n");
    displayCatFoodHeader();
    for (i = 0; i < MAX_NO_OF_PRODUCTS; i++)
    {
        displayCatFoodData(cat[i].productNumber, &cat[i].productPrice, cat[i].caloriPerSuggServ, &cat[i].productWeightPound);
    }

}
