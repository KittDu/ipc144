/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  :Kiet Dung Truong
Student ID#:122088230
Email      :kdtruong@myseneca.ca
Section    :ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
// Macro
#define maxProduct 3
#define gramInServing 64

// ----------------------------------------------------------------------------
// structures
typedef struct CatFoodInfo
{
    int prodSkuNum;
    int Calories;
    double prodPrice;
    double prodWeight;
} CatFoodInfo;
// ----------------------------------------------------------------------------
// function prototypes // 1. Get user input of int type and validate for a positive non-zero number //(return the number while also assigning it to the pointer argument)
int getIntPositive(int *input);
// 2. Get user input of double type and validate for a positive non-zero number //(return the number while also assigning it to the pointer argument)
double getDoublePositive(double *input);
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int maxP_numrod, const int Serve);
CatFoodInfo getCatFoodInfo(const int productsequencenumber);
// 5. Display the formatted table header
void displayCatFoodHeader(void);
// 6. Display a formatted record of cat food data
void displayCatFoodData( int productsku, double *productprice, int caloriesperserving, double *productweight);
// 7. Logic entry point
void start(void);
