/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  :Kiet Dung Truong
Student ID#:122088230
Email      :kdtruong@myseneca.ca
Section    :ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define lowestIncome 500.00
#define highestIncome 400000.00
#define maxItem 10
#define minItem 1
#define minCost 100.00
#include <stdio.h>
int main(void)
{
    double income, cost[maxItem], sumCost = 0.0,
                             filterCost;
    int i, item, priority[maxItem], flag[] = {0, 0, 0, 0, 0};
    char financeOption[maxItem];
    int years, months, Selection,
        filter, financeAvailable;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");
    while (flag[0] == 0)
    {
        printf("Enter your monthly NET income: $");
        scanf(" %lf", &income);
        if (income < lowestIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", lowestIncome);
        }
        else if (income > highestIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", highestIncome);
        }

        else
        {
            flag[0] = 1;
        }
        printf("\n");
    }

    while (flag[1] == 0)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf(" %d", &item);
        if (item < minItem || item > maxItem)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", minItem, maxItem);
        }
        else
        {
            flag[1] = 1;
        }
        printf("\n");
    }

    for (i = 0; i < item; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        while (flag[2] == 0)
        {
            printf("   Item cost: $");
            scanf(" %lf", &cost[i]);
            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
            else
            {
                flag[2] = 1;
            }
        }
        while (flag[3] == 0)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf(" %d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                flag[3] = 1;
            }
        }

        while (flag[4] == 0)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOption[i]);
            if (financeOption[i] != 'n' && financeOption[i] != 'y')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {
                flag[4] = 1;
            }
        }
        flag[2] = 0;
        flag[3] = 0;
        flag[4] = 0;
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < item; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOption[i], cost[i]);
        sumCost += cost[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n", sumCost);
    do
    {
        printf("\n");

        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &Selection);
        printf("\n");

        if (Selection > 2)
        {
            printf("ERROR: Invalid menu selection.\n");
        }
        else if (Selection == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", sumCost);
            months = sumCost / income + 1;
            years = months / 12;
            months = months % years;
            printf("Forecast: %d years, %d months\n", years, months);

            financeAvailable = 0;
            for (i = 0; i < item; i++)
            {
                if (financeOption[i] == 'y')
                {
                    financeAvailable = 1;
                }
            }
            if (financeAvailable == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                printf("====================================================\n");
            }
        }
        else if (Selection == 2)
        {
            do
            {

                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &filter);
                if (filter < 1 || filter > 3)
                {

                    printf("ERROR: priotity must be 1-3.\n");
                }
            } while (filter < 1 || filter > 3);
            printf("\n");
            printf("====================================================\n");

            printf("Filter:   by priority (%d)\n", filter);
            // Amount
            filterCost = 0.0;
            for (i = 0; i <= item; i++)
            {
                if (priority[i] == filter)
                {
                    filterCost += cost[i];
                }
            }
            printf("Amount:   $%1.2lf\n", filterCost);
            // Forecast
            months = (filterCost / income) + 1;
            years = months / 12;
            months = months % 12;
            printf("Forecast: %d years, %d months\n", years, months);
            // Finance option
            financeAvailable = 0;
            for (i = 0; i <= 3; i++)
            {
                if (financeOption[i] == 'y' && priority[i] == filter)
                {
                    financeAvailable = 1;
                }
            }
            if (financeAvailable == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (Selection == 0)
        {
            printf("Best of luck in all your future endeavours!\n");
        }
    } while (Selection != 0);
    return 0;
}
