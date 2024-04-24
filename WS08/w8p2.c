/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  :Kiet 
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
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


int getIntPositive (int *intptr)
{
    int value;
    do
    {
        scanf(" %d", &value);
        if (value <=0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);
    if (intptr != NULL)
    {
        *intptr = value;
    }
    return value;
    
}

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
//2. Get user input of double type and validate for a positive non-zero number
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
    printf("\nCat Food Product #%d\n", prodNum );
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
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double *pnd, double *kg)
{
	double o = *pnd / lbsInKg;
	if (kg != NULL)
	{
		*kg = o;
	}
	return o;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double *pnd, int *Gram)
{
	double t = *pnd;
	double ew = convertLbsKg(&t, &ew) * 1000;
	if (Gram != NULL)
	{
		*Gram = ew;
	}
	return ew;
}

// 10. convert lbs: kg and g
void convertLbs(const double *pnd, double *kg, int *g)
{
	*kg = *pnd / lbsInKg;
	*g = *pnd / lbsInKg * 1000;
}

// 11. calculate: servings based on gPerServ
double calculateServings(int gram_serving, int weight_gram, double *Total_serving)
{
	*Total_serving = ((double)weight_gram / gram_serving);
	return *Total_serving;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double Price, double Total_Serving, double *Cost_Per_Serving)
{
	*Cost_Per_Serving = Price / Total_Serving;
	return *Cost_Per_Serving;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double price, double cal, double Total_serving, double *cost_per_cal)
{
	*cost_per_cal = (price / cal) / Total_serving;
	return *cost_per_cal;
}

// 14. Derive a reporting detail record based on the cat food product data
ReportData calculateReportData(CatFoodInfo prod)
{
	ReportData report = {0};
	report.sku2 = prod.prodSkuNum;
	report.price2 = prod.prodPrice;
	report.TotalServing = calculateServings(gramInServing, convertLbsG(&prod.prodWeight, &report.weightGram), &report.TotalServing);
	report.costPerServing = calculateCostPerServing(prod.prodPrice, report.TotalServing, &report.costPerServing);
	report.weightLbs = prod.prodWeight;
	report.costCalPerServing = calculateCostPerCal(prod.prodPrice, prod.Calories, report.TotalServing, &report.costCalPerServing);
	report.calories2 = prod.Calories;
	report.weightKg = convertLbsKg(&prod.prodWeight, &report.weightKg);
	report.weightGram = convertLbsG(&prod.prodWeight, &report.weightGram);
	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", gramInServing);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(ReportData Data, int t)
{
	int i = 0;
	if (i == t)
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", Data.sku2, Data.price2, Data.weightLbs, Data.weightKg, Data.weightGram, Data.calories2, Data.TotalServing, Data.costPerServing, Data.costCalPerServing);
	}
	else
	{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", Data.sku2, Data.price2, Data.weightLbs, Data.weightKg, Data.weightGram, Data.calories2, Data.TotalServing, Data.costPerServing, Data.costCalPerServing);
	}
}

// 17. Display the findings (cheapest)
void diplayFinalAnalysis(int SKU, double price)
{
	printf("\nFinal Analysis");
	printf("\n--------------");
	printf("\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:00%d Price: $%.2lf\n\nHappy shopping!\n", SKU, price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start()
{
	CatFoodInfo prod[maxProduct] = {{0}};
	int maxProductNum = 3, i;
	int serve = 64;
	openingMessage(maxProductNum, serve);
	for (i = 0; i < maxProductNum; i++)
	{
		prod[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < maxProductNum; i++)
	{
		displayCatFoodData(prod[i].prodSkuNum, &prod[i].prodPrice, prod[i].Calories, &prod[i].prodWeight);
	}
	ReportData report[maxProduct] = {{0}};
	for (i = 0; i < maxProductNum; i++)
	{
		report[i] = calculateReportData(prod[i]);
	}
	displayReportHeader();
	int j, t;
	i = 0;
	for (i = 0; i < maxProductNum; i++)
	{
		for (j = 0; j < maxProductNum; j++)
		{
			if (report[i].costPerServing > report[j].costPerServing)
			{
				t = j;
			}
		}
		j = 0;
	}
	for (i = 0; i < maxProductNum; i++)
	{
		if (i != 0)
		{
			displayReportData(report[i], t - i);
		}
		else
		{
			displayReportData(report[i], t);
		}
	}
	diplayFinalAnalysis(prod[t].prodSkuNum, prod[t].prodPrice);
	return;
}