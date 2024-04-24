/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Kiet Dung Truong
Student ID#: 122088230
Email      : kdtruong@myseneca.ca
Section    : ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{ // a) variable declarations
       // You will need this when converting from grams to pounds (lbs)
       const double GRAMS_IN_LBS = 453.5924;

       char type1, bestServedWithCream1,
           type2, bestServedWithCream2,
           type3, bestServedWithCream3;
       int weight1,
           weight2,
           weight3;

       char chosenType,
           withCream;
       int dailyServing;

       // b) Product data input
       printf("Take a Break - Coffee Shop\n");
       printf("==========================\n");
       printf("\nEnter the coffee product information being sold today...\n");
       printf("\nCOFFEE-1...\n");

       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &type1);
       printf("Bag weight (g): ");
       scanf(" %d", &weight1);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &bestServedWithCream1);

       printf("\nCOFFEE-2...\n");
       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &type2);
       printf("Bag weight (g): ");
       scanf(" %d", &weight2);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &bestServedWithCream2);

       printf("\nCOFFEE-3...\n");
       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &type3);
       printf("Bag weight (g): ");
       scanf(" %d", &weight3);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &bestServedWithCream3);
       // c) Display product data
       printf("\n");
       printf("---+------------------------+---------------+-------+\n");
       printf("   |    Coffee              |   Packaged    | Best  |\n");
       printf("   |     Type               |  Bag Weight   | Served|\n");
       printf("   +------------------------+---------------+ With  |\n");
       printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
       printf("---+------------------------+---------------+-------|\n");
       printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
              type1 == 'l' || type1 == 'L',
              type1 == 'm' || type1 == 'M',
              type1 == 'r' || type1 == 'R',
              weight1,
              weight1 / GRAMS_IN_LBS,
              bestServedWithCream1 == 'Y' || bestServedWithCream1 == 'y');
       printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
              type2 == 'l' || type2 == 'L',
              type2 == 'm' || type2 == 'M',
              type2 == 'r' || type2 == 'R',
              weight2, weight2 / GRAMS_IN_LBS,
              bestServedWithCream2 == 'Y' || bestServedWithCream2 == 'y');
       printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
              type2 == 'l' || type2 == 'L',
              type3 == 'm' || type3 == 'M',
              type3 == 'r' || type3 == 'R',
              weight3, weight3 / GRAMS_IN_LBS,
              bestServedWithCream3 == 'Y' || bestServedWithCream3 == 'y');
       printf("\n");
       // d) Customer preference input (1st time)
       printf("Enter how you like your coffee...\n");
       printf("\n");

       printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
       scanf(" %c", &chosenType);

       printf("Do you like your coffee with cream ([Y]es,[N]o): ");
       scanf(" %c", &withCream);

       printf("Typical number of daily servings: ");
       scanf(" %d", &dailyServing);
       printf("\n");

       printf("The below table shows how your preferences align to the available products:\n");
       printf("\n");

       printf("--------------------+-------------+-------+\n");
       printf("  |     Coffee      |  Packaged   | With  |\n");
       printf("ID|      Type       | Bag Weight  | Cream |\n");
       printf("--+-----------------+-------------+-------+\n");
       printf(" 1|       %d         |      %d      |   %d   |\n",
              ((type1 == 'l' || type1 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type1 == 'm' || type1 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type1 == 'r' || type1 == 'R') && (chosenType == 'r' || chosenType == 'R')),
              ((dailyServing >= 1 && dailyServing <= 4) && weight1 == 250) || ((dailyServing >= 5 && dailyServing <= 9) && weight1 == 500) || ((dailyServing >= 10) && weight1 == 1000),
              ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream1 == 'y' || bestServedWithCream1 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream1 == 'n' || bestServedWithCream1 == 'N')));
       printf(" 2|       %d         |      %d      |   %d   |\n",
              ((type2 == 'l' || type2 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type2 == 'm' || type2 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type2 == 'r' || type2 == 'R') && (chosenType == 'r' || chosenType == 'R')),
              ((dailyServing >= 1 && dailyServing <= 4) && weight2 == 250) || ((dailyServing >= 5 && dailyServing <= 9) && weight2 == 500) || ((dailyServing >= 10) && weight2 == 1000),
              ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream2 == 'y' || bestServedWithCream2 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream2 == 'n' || bestServedWithCream2 == 'N')));

       printf(" 3|       %d         |      %d      |   %d   |\n",
              ((type3 == 'l' || type3 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type3 == 'm' || type3 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type3 == 'r' || type3 == 'R') && (chosenType == 'r' || chosenType == 'R')),
              ((dailyServing >= 1 && dailyServing <= 4) && weight3 == 250) || ((dailyServing >= 5 && dailyServing <= 9) && weight3 == 500) || ((dailyServing >= 10) && weight3 == 1000),
              ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream3 == 'y' || bestServedWithCream3 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream3 == 'n' || bestServedWithCream3 == 'N')));

       printf("\n");
       // d) Customer preference input (2nd time)
       printf("Enter how you like your coffee...\n");
       printf("\n");

       printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
       scanf(" %c", &chosenType);
       printf("Do you like your coffee with cream ([Y]es,[N]o): ");
       scanf(" %c", &withCream);
       printf("Typical number of daily servings: ");
       scanf(" %d", &dailyServing);
       printf("\n");

       printf("The below table shows how your preferences align to the available products:\n");
       printf("\n");

       printf("--------------------+-------------+-------+\n");
       printf("  |     Coffee      |  Packaged   | With  |\n");
       printf("ID|      Type       | Bag Weight  | Cream |\n");
       printf("--+-----------------+-------------+-------+\n");
       printf(" 1|       %d         |      %d      |   %d   |\n",
              ((type1 == 'l' || type1 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type1 == 'm' || type1 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type1 == 'r' || type1 == 'R') && (chosenType == 'r' || chosenType == 'R')),
              ((dailyServing >= 1 && dailyServing <= 4) && weight1 == 250) || ((dailyServing >= 5 && dailyServing <= 9) && weight1 == 500) || ((dailyServing >= 10) && weight1 == 1000),
              ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream1 == 'y' || bestServedWithCream1 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream1 == 'n' || bestServedWithCream1 == 'N')));
       printf(" 2|       %d         |      %d      |   %d   |\n",
              ((type2 == 'l' || type2 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type2 == 'm' || type2 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type2 == 'r' || type2 == 'R') && (chosenType == 'r' || chosenType == 'R')),
              ((dailyServing >= 1 && dailyServing <= 4) && weight2 == 250) || ((dailyServing >= 5 && dailyServing <= 9) && weight2 == 500) || ((dailyServing >= 10) && weight2 == 1000),
              ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream2 == 'y' || bestServedWithCream2 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream2 == 'n' || bestServedWithCream2 == 'N')));

       printf(" 3|       %d         |      %d      |   %d   |\n",
              ((type3 == 'l' || type3 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type3 == 'm' || type3 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type3 == 'r' || type3 == 'R') && (chosenType == 'r' || chosenType == 'R')),
              ((dailyServing >= 1 && dailyServing <= 4) && weight3 == 250) || ((dailyServing >= 5 && dailyServing <= 9) && weight3 == 500) || ((dailyServing >= 10) && weight3 == 1000),
              ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream3 == 'y' || bestServedWithCream3 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream3 == 'n' || bestServedWithCream3 == 'N')));
       // deMorgan's Law
       // printf(" 3|       %d         |      %d      |   %d   |\n",
       //        ((type3 == 'l' || type3 == 'L') && (chosenType == 'l' || chosenType == 'L')) || ((type3 == 'm' || type3 == 'M') && (chosenType == 'm' || chosenType == 'M')) || ((type3 == 'r' || type3 == 'R') && (chosenType == 'r' || chosenType == 'R')),
       //        !((((dailyServing < 1) || (dailyServing > 4)) || weight3 != 250) && (((dailyServing < 5) || (dailyServing > 9)) || weight3 != 500) && (((dailyServing < 10) || weight3 != 1000))),
       //        ((withCream == 'y' || withCream == 'Y') && (bestServedWithCream3 == 'y' || bestServedWithCream3 == 'Y')) || ((withCream == 'n' || withCream == 'N') && (bestServedWithCream3 == 'n' || bestServedWithCream3 == 'N')));

       printf("\n");

       printf("Hope you found a product that suits your likes!\n");

       return 0;
}

/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/
