/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
{
    char loopType;
    int i ,
        iteration  ;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &iteration);

        if (loopType == 'D')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                i = 0;
                printf("DO-WHILE: ");
              do
              {
                printf("D");
                i++;
              } while (i < iteration);
              printf ("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loopType == 'W')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf ("WHILE   : ");
                i = 0;
                 while (i < iteration)
                {
                printf ("W");
                i++;
                }
                printf ("\n\n");
            }
            else
            {
                printf ("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loopType == 'F')
        {
            if (iteration >= 3 && iteration <= 20)
            {
                printf ("FOR     : ");
               
                for (i=0; i < iteration; i++)
                {
                printf ("F");
                }
                printf ("\n\n");
            }
        
         else
            {
                printf ("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loopType == 'Q')
        {
            if (iteration == 0)
             { printf ("\n");
             printf ("+--------------------+\n");
             printf ("Loop application ENDED\n");
             printf ("+--------------------+\n");
            }
        
        else
        {
            printf ("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
    }
    while (loopType != 'Q' || iteration != 0); // Why ||?

    return 0;
}


