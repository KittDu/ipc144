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

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearinputbuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);
// input an integer
int inputInt(void);
// inputIntPositive Function
int inputIntPositive(void);
// inputIntRange Function????
int inputIntRange (int min, int max);
//input character Function
char inputCharOption (const char pvalidOption[]);
// inputCString Function
void inputCString(char *cstring, int min, int max);
// display correct phone number format
void displayFormattedPhone(const char *digits);






//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////














// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
