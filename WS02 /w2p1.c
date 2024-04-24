/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Kiet Dung Truong
Student ID#: 122088230
Email      : kdtruong@myseneca.ca
Section    :ZII

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double priceOfSmallShirt, priceOfMediumShirt, priceOfLargeShirt,subTotal,taxes, total;
    int numberOfShirtPattyIsBuying , roundTaxes ;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf ("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceOfSmallShirt);
   
    
    printf("Enter the price for a MEDIUM shirt: $" );
    scanf("%lf", &priceOfMediumShirt);
    
    
    printf("Enter the price for a LARGE shirt: $" );
    scanf("%lf", &priceOfLargeShirt);
    printf ("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", priceOfSmallShirt);
    printf("MEDIUM : $%.2lf\n", priceOfMediumShirt);
    printf("LARGE  : $%.2lf\n", priceOfLargeShirt);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
      printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberOfShirtPattyIsBuying);
  
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberOfShirtPattyIsBuying);
  
  subTotal = (numberOfShirtPattyIsBuying * priceOfSmallShirt);
  printf("Sub-total: $%8.4lf\n", subTotal);
  
  taxes = (subTotal*TAX);
  roundTaxes = (taxes + 0.005) *100 ;
  printf("Taxes    : $ %.4lf\n", roundTaxes/100.0);
    
    total = subTotal + roundTaxes/100.0 ;
    printf ("Total    : $%.4lf\n", total);

    return 0;
}

