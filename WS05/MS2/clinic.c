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
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;
    
    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
            case 0:
                printf("Are you sure you want to exit? (y|n): ");
                selection = !(inputCharOption("yn") == 'y');
                putchar('\n');
                if (!selection)
                {
                    printf("Exiting system... Goodbye.\n\n");
                }
                break;
            case 1:
                menuPatient(data->patients, data->maxPatient);
                break;
            case 2:
                printf("<<< Feature not yet available >>>\n\n");
                break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;
    
    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
            case 1:
                displayAllPatients(patient, max, FMT_TABLE);
                suspend();
                break;
            case 2:
                searchPatientData(patient, max);
                break;
            case 3:
                addPatient(patient, max);
                suspend();
                break;
            case 4:
                editPatient(patient, max);
                break;
            case 5:
                removePatient(patient, max);
                suspend();
                break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;
    
    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        
        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }
        
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt){
    
    int i = 0;
    int count = 0;
    displayPatientTableHeader();
    for (i=0; i < max; i++) {
        if (patient[i].patientNumber != 0 ) {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    printf("\n");
    //if there were no eligible records to display.
    if (count == 0)
    {
        printf("*** No records found");
    }
    printf("\n");
    
    
}



// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max){
    int selection = 1;
    // dowhile-> while
    while (selection != 0 )
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selection);
       
        
        if (selection == 1) {
            searchPatientByPatientNumber(patient, max);
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
        }
    }
    printf("\n");
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max){
    int i;
    int count = 0;
    for (i=0; i<max; i++) {
        // if patient array has free element (when patient number == 0)
        if (patient[i].patientNumber == 0) {
            // store array index => determine the unique patient number and store
            patient[i].patientNumber = nextPatientNumber(patient, max); //nextPatientNumber(&patient[i], max);
            // get user input new record
            inputPatient(&patient[i]);
            count++;
            // Display confirmation message
            printf("*** New patient record added ***\n");
            printf("\n");
            i = max;
        }
    }
    if (count == 0) {
        printf("ERROR: Patient listing is FULL!\n");
        printf("\n");
    }
}
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max){
    int patientNumber = 0;
    int patientPosition = 0;
    // prompt user to input patient number for the record to be edited
    printf("Enter the patient number: ");
    //    scanf("%d", &patientNumber);
    patientNumber = inputIntPositive();
    // create patientPosition to check exist
    patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    if (patientPosition >= 0) {
        menuPatientEdit(&patient[patientPosition]);
//        menuPatientEdit(patient);
        
    }
    else if (patientPosition < 0)
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n");
        printf("\n");
        suspend();
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max){
    int patientNumber = 0, patientPosition = 0;
    char userSelection = 0;
    // prompt user to input patient number for the record to be edited
    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    //    scanf("%d", &patientNumber);
    // locate patienNumber to see if it exists
    patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    
    if (patientPosition >=0) {
        displayPatientData(&patient[patientPosition], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf("%c", &userSelection );
        if (userSelection == 'y') {
            // confirmatien message
            patient[patientPosition].patientNumber = 0;
            patient[patientPosition].name[0] = '\0';
            patient[patientPosition].phone.description[0] = '\0';
            patient[patientPosition].phone.number [0] = '\0';
            
            printf("Patient record has been removed!\n");
        }
        else if (userSelection == 'n')
        {
            printf("Operation aborted.\n");
        }
        else
            printf("Only choose 'y' or 'n'\n");
    }
    else // patientPosition < 0
    {
        printf("\n");
        printf("ERROR: Patient record not found!\n");
        printf("\n");
    }
    //
    clearinputbuffer();
    printf("\n");
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max){
    
    int patientNumber=0;
    int patientIndexNumber=0;
    printf("\n");
    
    printf("Search by patient number: ");
    // prompt user to input patient Number
    patientNumber = inputIntPositive();
//    printf("\n");
    // locate the record to see if it exists
    patientIndexNumber = findPatientIndexByPatientNum(patientNumber, patient/*?*/, max);
    
    if (patientIndexNumber >= 0) {
        
        displayPatientData(&patient[patientIndexNumber], FMT_FORM);
    }
    else {
        //
        printf("\n");
        printf("*** No records found ***");
    }
    printf("\n");
    suspend();
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max){
    //
    printf("\n");
    char userIInput[PHONE_LEN+1] = { 0 };
    int count = 0;
    int i;
    printf("Search by phone number: ");
    // prompt user to input phone number
    inputCString(userIInput, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    
    // locate user input if it exists
    for (i= 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, userIInput) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
//            displayPatientData(patient, FMT_TABLE);
            count++;
        }
        if (count == 0) 
        {
            printf("\n");
            printf("*** No records found ***");
        }
    }
    printf("\n");
    suspend();
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max){
    int i;
    int maxNumber = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber >= maxNumber) {
            maxNumber = patient[i].patientNumber + 1;
        }
    }
    // return calculated next number
    return maxNumber;
    //    //temporary return measure
//    return 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max){
    int i = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber)
        {
            printf("\n");
            // return the index position of the matched element
            return i;
        }
    }
    return -1;
    
    //    //temporary return measure
    //    return  1;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient){
    printf("Patient Data Input\n");
    printf("-----------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
  
    // Passing 'struct Phone' to parameter of incompatible type 'struct Phone *'; take the address with &
    printf("\n");
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone){
    int selection;
    char description1[PHONE_DESC_LEN+1] = {"CELL"};
    char description2[PHONE_DESC_LEN+1] = {"HOME"};
    char description3[PHONE_DESC_LEN+1] = {"WORK"};
    char description4[PHONE_DESC_LEN+1] = {"TBD"};
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &selection);
    printf("\n");
    
    if (selection == 1)
    {
        strcpy(phone->description, description1);
    }
    else if (selection == 2)
    {
        strcpy(phone->description, description2);
    }
    else if (selection == 3)
    {
        strcpy(phone->description, description3);
        
    }
    else if (selection == 4)
    {
        strcpy(phone->description, description4);
    }
    if (selection != 4) {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        printf("\n");
    }
    else
    {
        // store phone number in a safe place
        phone->number[0] = '\0';
    }
}
