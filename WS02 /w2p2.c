
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
       const double TAX = 0.13;
       const char patSize = 'S', salSize = 'M', tomSize = 'L';
       double priceOfSmallShirt, priceOfMediumShirt, priceOfLargeShirt;
       int numberOfShirtPattyIsBuying;
       printf("Set Shirt Prices\n");
       printf("================\n");
       printf("Enter the price for a SMALL shirt: $");
       scanf("%lf", &priceOfSmallShirt);

       printf("Enter the price for a MEDIUM shirt: $");
       scanf("%lf", &priceOfMediumShirt);

       printf("Enter the price for a LARGE shirt: $");
       scanf("%lf", &priceOfLargeShirt);

       printf("\n");
       printf("Shirt Store Price List\n");
       printf("======================\n");
       printf("SMALL  : $%.2lf\n", priceOfSmallShirt);
       printf("MEDIUM : $%.2lf\n", priceOfMediumShirt);
       printf("LARGE  : $%.2lf\n", priceOfLargeShirt);
       printf("\n");
       printf("Patty's shirt size is '%c'\n", patSize);
       printf("Number of shirts Patty is buying: ");
       scanf("%d", &numberOfShirtPattyIsBuying);

       int numberOfShirtTommyIsBuying, numberOfShirtSallyIsBuying;
       printf("\nTommy's shirt size is '%c'\n", tomSize);
       printf("Number of shirts Tommy is buying: ");
       scanf("%d", &numberOfShirtTommyIsBuying);

       printf("\nSally's shirt size is '%c'\n", salSize);
       printf("Number of shirts Sally is buying: ");
       scanf("%d", &numberOfShirtSallyIsBuying);

       printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
       printf("-------- ---- ----- --- --------- --------- ---------\n");

       double pSub = numberOfShirtPattyIsBuying * priceOfSmallShirt,
              sSub = numberOfShirtSallyIsBuying * priceOfMediumShirt,
              tSub = numberOfShirtTommyIsBuying * priceOfLargeShirt,
              subTotal = pSub + sSub + tSub;

       int prSub = (numberOfShirtPattyIsBuying * priceOfSmallShirt + 0.005) * 100,
           srSub = (numberOfShirtSallyIsBuying * priceOfMediumShirt + 0.005) * 100,
           trSub = (numberOfShirtTommyIsBuying * priceOfLargeShirt + 0.005) * 100,
           rsubTotal = (pSub + sSub + tSub + 0.005) * 100;

       double pTax = pSub * TAX,
              sTax = sSub * TAX,
              tTax = tSub * TAX;

       int prTax = (pTax + 0.005) * 100,
           srTax = (sTax + 0.005) * 100,
           trTax = (tTax + 0.005) * 100,
           rtax = (pTax+sTax+tTax + 0.005) * 100;

       double pTotal = pSub + pTax,
              sTotal = sSub + sTax,
              tTotal = tSub + tTax;

       int prTotal = (pSub + pTax + 0.005) * 100,
           srTotal = (sSub + sTax + 0.005) * 100,
           trTotal = (tSub + tTax + 0.005) * 100,
           rtotal = (pTotal + sTotal + tTotal + 0.005) * 100;

       printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, priceOfSmallShirt, numberOfShirtPattyIsBuying,
              prSub / 100.0, prTax / 100.0, prTotal / 100.0);

       printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, priceOfMediumShirt, numberOfShirtSallyIsBuying,
              srSub / 100.0, srTax / 100.0, srTotal / 100.0);

       printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, priceOfLargeShirt, numberOfShirtTommyIsBuying,
              trSub / 100.0, trTax / 100.0, trTotal / 100.0);
       printf("-------- ---- ----- --- --------- --------- ---------\n");
       printf("%33.4lf %9.4lf %9.4lf\n\n", rsubTotal / 100.0, rtax / 100.0, rtotal / 100.0);

       printf("Daily retail sales represented by coins\n");
       printf("=======================================\n");
       printf("\n");
       printf("Sales EXCLUDING tax\n");
       printf("Coin     Qty   Balance\n");
       printf("-------- --- ---------\n");
       printf("%22.4lf\n", (double)rsubTotal / 100.0);

        
       /* int ql = (bt *100 ) / 100;
       double  bl = (((int)bt*100) % 100) /100.0;
       printf("Loonies %3d %9.4lf\n", ql, bl);*/ // way1 
       
 
       int qt = rsubTotal / 200;
       double bt = (rsubTotal % 200) / 100.0;
       printf("Toonies  %3d %9.4lf\n", qt, bt);
       
        int ql = (rsubTotal % 200) / 100;
        double  bl = ((rsubTotal % 200) % 100) /100.0;
        printf("Loonies  %3d %9.4lf\n", ql, bl);
    
       int qq = ((rsubTotal % 200) % 100)/25;
       double bq= ((rsubTotal % 200) % 100 %25)/100.0; 
    printf("Quarters %3d %9.4lf\n", qq, bq);
    
    int qd = (((rsubTotal % 200) % 100)%25)/10;
    double bd = ((((rsubTotal % 200) % 100)%25)%10)/100.0;
    printf ("Dimes    %3d %9.4lf\n",qd, bd); 
    
    int qn =((((rsubTotal % 200) % 100)%25)%10) /5; 
    double bn = (((((rsubTotal % 200) % 100)%25)%10)%5)/100.0;
    printf ("Nickels  %3d %9.4lf\n",qn, bn);
    
    int qp = ((((((rsubTotal % 200) % 100)%25)%10)%5))/1; 
    double bp = ((((((rsubTotal % 200) % 100)%25)%10)%5)%1)/100.0;
    printf ("Pennies  %3d %9.4lf\n",qp, bp);
    
   int totalShirt = numberOfShirtTommyIsBuying + numberOfShirtPattyIsBuying + numberOfShirtSallyIsBuying; 
     double ave = (subTotal / totalShirt); ; 
   printf ("\n");

   printf ("Average cost/shirt: $%.4lf\n\n",ave);
   printf ("Sales INCLUDING tax\n");
   printf ("Coin     Qty   Balance\n");
   printf ("-------- --- ---------\n");
   printf ("              %.4lf\n",(double) rtotal/100.0);
  
    int qtt = rtotal / 200;
       double btt = (rtotal % 200) / 100.0;
       printf("Toonies  %3d %9.4lf\n", qtt, btt);
       
         int qlt = ((rtotal % 200) /100 );
       double blt = ((rtotal % 200) % 100 )/100.0 ;
       printf("Loonies  %3d %9.4lf\n", qlt, blt);
       
       int qqt = ((rtotal % 200) % 100)/25;
       double bqt= ((rtotal % 200) % 100 %25)/100.0; 
    printf("Quarters %3d %9.4lf\n", qqt, bqt);
    
    int qdt = (((rtotal % 200) % 100)%25)/10;
    double bdt = ((((rtotal % 200) % 100)%25)%10)/100.0;
    printf ("Dimes    %3d %9.4lf\n",qdt, bdt); 
    
    int qnt =((((rtotal % 200) % 100)%25)%10) /5; 
    double bnt = (((((rtotal % 200) % 100)%25)%10)%5)/100.0;
    printf ("Nickels  %3d %9.4lf\n",qnt, bnt);
    
    int qpt = ((((((rtotal % 200) % 100)%25)%10)%5))/1; 
    double bpt = ((((((rtotal % 200) % 100)%25)%10)%5)%1)/100.0;
    printf ("Pennies  %3d %9.4lf\n\n",qpt, bpt);
    printf("Average cost/shirt: $%.4lf\n",((double)rtotal/totalShirt)/100.0);
   
   

       return 0;
}
