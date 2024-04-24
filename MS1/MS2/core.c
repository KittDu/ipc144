/*/////////////////////////////////////////////////////////////////////////
 Assignment 1 - Milestone 2
 Full Name  :Kiet Dung Truong
 Student ID#: 122088230
 Email      :kdtruong@myseneca.ca
 Section    :ZII
 Authenticity Declaration:
 I declare this submission is the result of my own work and has not been
 shared with any other student or 3rd party content provider. This submitted
 piece of work is entirely of my own creation.
 /////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer

// Clear the standard input buffer
void clearinputbuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearinputbuffer();
    putchar('\n');
}
// input an integer
int inputInt(void)
{
    char newline = 'x';
    int value = 0;
    while (newline != '\n')
    {
        scanf("%d%c", &value, &newline);
        if (newline != '\n')
        {
            clearinputbuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return value;
}
// inputIntPositive Function
int inputIntPositive(void)
{
    int value;
    do
    {
        value = inputInt();
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);
    return value;
}
// inputIntRange Function????
int inputIntRange(int min, int max)
{
    char newline = 'x';
    int value = 0;
    while (newline != '\n' || (value > max || value < min))
    {
        scanf("%d%c", &value, &newline);
        if (newline != '\n')
        {
            clearinputbuffer();
            printf("Error! Input a whole number: ");
        }
        else if (value > max || value < min)
        {
            /*if (value > max || value < min) {*/
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    }
    return value;
}
// inputCharOption Function
char inputCharOption (const char pvalidOption[])
{
    char character;
    int flag = 0;
    int i;
    do
    {
        scanf(" %c", &character);
        for (i = 0; pvalidOption[i] != '\0'; i++)
        {
            if (character == pvalidOption[i])
            {
                flag++;
            }
        }
        if (flag == 0)
        {
            printf("ERROR: Character must be one of [qwErty]: ");
        }
    } while (flag == 0);
    clearinputbuffer();
    return character;
}
// inputCString Function
void inputCString(char *cstring, int min, int max)
{
    int length = 0;
    char userInput[SIZE+1] = {0};
    do {
        // read user input until newline, ignore newline
        scanf("%[^\n]%*c", userInput);
        length = strlen(userInput);
        if (length < min || length > max) 
        {
            if (min == max) {
                printf("ERROR: String length must be exactly %d chars: ", max);
            }
            else if (length > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else if (min < max)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
            clearinputbuffer();
        }
    } while (length > max || length < min);
    strcpy(cstring, userInput);
    clearinputbuffer();
}
// displayFormattedPhone Function
void displayFormattedPhone(const char *digits)
{
    int i;
    int length = 0;
    int counter = 0;
    
    if (digits != NULL)
    {
        for (i = 0; digits[i] != '\0'; i++)
        {
            length++;
        }
    }
    if (length == 10)
    {
        for (i = 0; digits[i] != '\0'; i++)
        {
            if (digits[i] >= '0' && digits[i] <= '9')
            {
                counter++;
            }
        }
        if (counter == 10)
        {
            
            printf("(");
            for (i = 0; digits[i] != '\0'; i++)
            {
                if (i < 3)
                {
                    printf("%c", digits[i]);
                }
            }
            printf(")");
            for (i = 0; digits[i] != '\0'; i++)
            {
                if (i >= 3 && i < 6)
                {
                    printf("%c", digits[i]);
                }
            }
            printf("-");
            for (i = 0; digits[i] != '\0'; i++)
            {
                if (i >= 6 && i < 10)
                {
                    printf("%c", digits[i]);
                }
            }
        }
        else
        {
            printf("(___)___-____");
        }
    }
    else
    {
        printf("(___)___-____");
    }
}
