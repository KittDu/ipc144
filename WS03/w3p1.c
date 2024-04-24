
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Kiet Dung Truong
Student ID#: 122088230
Email      : kdtruong@myseneca.ca
Section    : ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    // declaration:
    const int id1 = 111,
              id2 = 222,
              id3 = 111;
    const double price1 = 111.49,
                price2 = 222.99,
                price3 = 334.49,
                average = (price1 + price2 + price3) / 3;
    const char tax1 = 'Y',
               tax2 = 'N',
               tax3 = 'N';

int result = tax1 == 'Y';
    // Code Block

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", id1);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%.4f\n\n", price1);

    printf("Product-2 (ID:%d)\n", id2);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%.4f\n\n", price2);

    printf("Product-3 (ID:%d)\n", id3);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%.4f\n\n", price3);

    printf("The average of all prices is: $%.4f\n\n", average);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\nSome Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n", result);
    printf("\n");
    result =  tax2=='N'&& tax3 == 'N';
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", result);
    printf("\n");
    result = price3 < testValue;
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, result);

    printf("\n");
    result = price3 > (price1 + price2);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", result);
    printf("\n");
    result = price1 >= (price3 - price2);
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n", result, price3 - price2);
    printf("\n");
    result = price2 >= average;
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", result );
    printf("\n");
    result = !(id2==id1 || id1==id3);
    printf("7. Based on product ID, product 1 is unique -> %d\n", result);
    printf("\n");
    result = !(id2==id1 || id2==id3);
    printf("8. Based on product ID, product 2 is unique -> %d\n",result );
    printf("\n");
    result = !(id3==id1 || id3==id2);
    printf("9. Based on product ID, product 3 is unique -> %d\n", result);
    return 0;
}

