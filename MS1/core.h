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
// Clear the standard input buffer
void clearinputbuffer(void); 
// Wait for user to input the "enter" key to continue 
void suspend(void);
//6.
// void inputCString(char *cstring, int min, int max); 
int inputInt(void);
int inputIntPositive(void);
int inputIntRange (int min, int max);
char inputCharOption (const char pvalidOption[]);
// void inputCString (char*pcstring, int min, int max);
void inputCString(char *cstring, int min, int max);
void displayFormattedPhone(const char *digits);
