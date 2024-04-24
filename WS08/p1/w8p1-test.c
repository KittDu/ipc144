/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

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


int getIntPositive(int *P_num)
{
	int test_no;
	do
	{
		scanf(" %d", &test_no);
		if (test_no <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (test_no <= 0);
	if (P_num != NULL)
	{
		*P_num = test_no;
	}
	return test_no;
}
double getDoublePositive(double *P_num)
{
	double test_no;
	do
	{
		scanf(" %lf", &test_no);
		if (test_no <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (test_no <= 0);
	if (P_num != NULL)
	{
		*P_num = test_no;
	}
	return test_no;
}
void openingMessage (const int maxP_numrod, const int Serve)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", maxP_numrod);
	printf("NOTE: A 'serving' is %dg\n", Serve);
	return;
}
struct CatFoodInfo getCatFoodInfo(const int prodNum)
{
	struct CatFoodInfo catFoods[PROD] = {{0}};
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
	printf("WEIGHT (LBS)   : ");
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
void displayCatFoodHeader(void)
{
	printf("\nSKU$PriceBag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}
void displayCatFoodData(const int prodSkuNum, const double *prodPriceP, const int Calories, const double *prodWeightP)
{
	printf("%07d %10.2lf %10.1lf %8d\n", prodSkuNum, *prodPriceP, *prodWeightP, Calories);
	return;
}
void start(void)
{
	struct CatFoodInfo catFoods[PROD] = {{0}};
	int i;
	openingMessage(PROD, GMSERVING);
	for (i = 0; i < PROD; i++)
	{
		catFoods[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < PROD; i++)
	{
		displayCatFoodData(catFoods[i].prodSkuNum, &catFoods[i].prodPrice, catFoods[i].Calories, &catFoods[i].prodWeight);
	}
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
// double getDoublePositive (double *doubleptr)
// {
// 	do
// 	{
// 		scanf("%.lf", doubleptr);
// 	}while (*doubleptr < 0);
// 	return *doubleptr;
// }

// // 3. Opening Message (include the number of products that need entering)

// // 4. Get user input for the details of cat food product
// struct catFoodInfo getCatFoodInfo(const int number)
// {
//      int sku[maxProducts];
//     double price;
//     int calPerServing;
//     double weightInLbs;
//     struct catFoodInfo newCatFoodInfo ={int, double, int, double}; //create new instance to return newCatFoodInfo// wrong cuz number is const number = number +10;
// }

// // 5. Display the formatted table header
// void displayCatFoodHeader(void)
// {
// 	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
// 	printf("------- ---------- ---------- --------\n");
// }

// // 6. Display a formatted record of cat food data
// void displayCatFoodData (int sku, double *preceptor, int calories, double *weight ); // note => ()

// // 7. Logic entry point
