/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Kiet Dung Truong
Student ID#: 122088230
Email      : kdtruong@mysenca.ca
Section    : ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int appleNeed, orangeNeed, pearNeed, tomatoNeed, cabbageNeed,
        pickedNumber;
    int finishedShopping = 1; // flag
    while (finishedShopping != 0)
    {
    printf("Grocery Shopping\n");
    printf("================\n");
    
        do
        {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &appleNeed);

            if (appleNeed < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (appleNeed < 0);
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &orangeNeed);
            if (orangeNeed < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (orangeNeed < 0);
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &pearNeed);
            if (pearNeed < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pearNeed < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &tomatoNeed);

            if (tomatoNeed < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoNeed < 0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &cabbageNeed);

            if (cabbageNeed < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbageNeed < 0);
        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");
        while (appleNeed > 0)
        {
            while (appleNeed != 0)
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &pickedNumber);
                if (pickedNumber > appleNeed)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", appleNeed);
                }
                else if (pickedNumber <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (appleNeed == pickedNumber)
                {
                    appleNeed -= pickedNumber;
                    printf("Great, that's the apples done!\n");
                }
                else if (pickedNumber < appleNeed)
                {
                    appleNeed -= pickedNumber;
                    printf("Looks like we still need some APPLES...\n");
                }
            }
            printf("\n");
        }
        
        while (orangeNeed > 0)
        {
            while (orangeNeed != 0)
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &pickedNumber);
                if (pickedNumber > orangeNeed)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangeNeed);
                }
                else if (pickedNumber < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedNumber < orangeNeed)
                {
                    orangeNeed -= pickedNumber;
                    printf("Looks like we still need some ORANGES...\n");
                }
                else if (pickedNumber == orangeNeed)
                {
                    orangeNeed -= pickedNumber;
                    printf("Great, that's the oranges done!\n");
                }
            }
            printf("\n");
        }
        

        while (pearNeed > 0)
        {
            while (pearNeed != 0)
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &pickedNumber);
                if (pickedNumber > pearNeed)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pearNeed);
                }
                else if (pickedNumber < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedNumber < pearNeed)
                {
                    pearNeed -= pickedNumber;
                    printf("Looks like we still need some PEARS...\n");
                }
                else if (pickedNumber == pearNeed)
                {
                    pearNeed -= pickedNumber;
                    printf("Great, that's the pears done!\n");
                }
            }
            printf("\n");
        }

        while (tomatoNeed > 0)
        {
            while (tomatoNeed != 0)
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &pickedNumber);
                if (pickedNumber > tomatoNeed)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoNeed);
                }
                else if (pickedNumber < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedNumber < tomatoNeed)
                {
                    tomatoNeed -= pickedNumber;
                    printf("Looks like we still need some TOMATOES...\n");
                }
                else if (pickedNumber == tomatoNeed)
                {
                    tomatoNeed -= pickedNumber;
                    printf("Great, that's the tomatoes done!\n");
                }
            }
            printf("\n");
        }


        while (cabbageNeed > 0)
        {
            while (cabbageNeed != 0)
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &pickedNumber);
                if (pickedNumber > cabbageNeed)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbageNeed);
                }
                else if (pickedNumber < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickedNumber < cabbageNeed)
                {
                    cabbageNeed -= pickedNumber;
                    printf("Looks like we still need some CABBAGES...\n");
                }
                else if (pickedNumber == cabbageNeed)
                {
                    cabbageNeed -= pickedNumber;
                    printf("Great, that's the cabbages done!\n");
                }
            }
            printf("\n");
        }
        
        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf(" %d", &finishedShopping);
        printf("\n");
    }
    
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}
