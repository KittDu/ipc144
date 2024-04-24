// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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
//
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
//
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
//
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
//
void inputCString(char *cstring, int min, int max)
{
	char character = 'x';
	int flag = 0;
	do
	{
		int length = 0;
		int i;
		for (i = 0; character != '\n' && length <= max; i++)
		{
			character = getchar();
			cstring[i] = character;
			length++;
		}
		if (character == '\n' && length <= (max + 1))
		{
			length--;
			cstring[length] = '\0';
		}
		else
		{
			cstring[max] = '\0';
			clearinputbuffer();
		}
		if (min != max)
		{
			if (length < min)
			{
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
				character = 'x';
			}
			else if (length > max)
			{
				printf("ERROR: String length must be no more than 6 chars: ");
				character = 'x';
			}
			else
			{
				flag = 1;
			}
		}
		else if (min == max)
		{
			if (length != min)
			{
				printf("ERROR: String length must be exactly 6 chars: ");
				character = 'x';
			}
			else
			{
				flag = 1;
			}
		}
	} while (flag == 0);
}
//
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