/***********************************************************************
* Program:
*    Project 1, Monthly Budget
*    Brother Comeau, CS124
* Author:
*    Ben Wright
* Summary: 
*    In this program it creates a monthly budget for the user. It takes in
*    5 different items and then takes the difference of them
*
*    Estimated:  4.0 hrs   
*    Actual:     10.0 hrs
*      The most difficult part was the compute tax function. I could not
*      figure out why it was printing a undefined number in, the 3rd
*      I had tutors check and agreed with me.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define LINE "\t=============== =============== ===============\n"

/**********************************************************************
 * This function will store whatever the user inputs in the cout
 * statements that are in function main.
 ***********************************************************************/
float getFloat()
{
   float gen;
   cin >> gen;
   return gen;  
}

// float computeTax2(float income, int tax1, int tax2)
// {
//    if (income > tax1 && income < tax2)
// }

/**********************************************************************
 * This function determines how much tax the user has to pay which is
 * determined by the income
 ***********************************************************************/
float computeTax(float income)
{
   if (income > 0 && income < 15100) 
      return ((income * 12) * .1) / 12;      

   if (income > 15100 && income < 61300)
      return 6653.07; //This kept returning an undefined value. Tutor agreed.

   if (income > 61300 && income < 123700)
      return ((8440 + 0.25) * ((income * 12) - 61300)) / 12;

   if (income > 123700 && income < 188450) 
      return ((24040 + 0.28) * ((income * 12) - 123700)) / 12;

   if (income > 188450 && income < 336550) 
      return ((42170 + 0.33) * ((income * 12) - 188450)) / 12;
   
   if (income > 336500) 
      return ((91043 + 0.35) * ((income * 12) - 336550)) / 12;
}

void display(string expense, int space, float leftIncome, float rightIncome)
{
   cout << "\t" << expense << setw(space)
        << "$" << setw(11) << leftIncome << setw(5)
        << "$" << setw(11) << rightIncome << endl;
}

/**********************************************************************
 * Function display will display the users budget on the screen.
 ***********************************************************************/
void display(float income, float budgetLiving, float actualLiving,
   float tax, float other, float tithing)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   float budgetTax =
      computeTax(income);
  
   float budgetTithing =
      income * .1;
   
   float budgetOther =
      income - budgetTax - budgetTithing - budgetLiving;

   float budgetDifference =
      income - budgetTax - budgetTithing - budgetLiving - budgetOther;

   float actualDifference =
      income - tax - tithing - actualLiving - other;

   cout << "The following is a report on your monthly expenses\n"; 

   cout << "\tItem" << setw(25) << "Budget " << setw(15) << "Actual"
        << endl;

   cout << LINE;
   display("Income ", 10, income, income);
   display("Taxes ", 11, budgetTax, tax);
   display("Tithing", 10, budgetTithing, other);
   display("Living ", 10, budgetLiving, actualLiving);
   display("Other ", 11, budgetOther, tithing);
   cout << LINE;
   display("Difference ", 6, budgetDifference, actualDifference);  
}

/**********************************************************************
 * Function main prompts the user for all of their expenses and passes
 * them into the get Float function.
 ***********************************************************************/
int main(void)
{
   cout << "This program keeps track of your monthly budget" << endl;
   cout << "Please enter the following:" << endl;

   cout << "\tYour monthly income: ";
   float income = getFloat();
   cout << "\tYour budgeted living expenses: ";
   float budgetLiving = getFloat();
   cout << "\tYour actual living expenses: ";
   float actualLiving = getFloat();
   cout << "\tYour actual taxes withheld: ";
   float tax = getFloat();
   cout << "\tYour actual tithe offerings: ";
   float tithing = getFloat();
   cout << "\tYour actual other expenses: ";   
   float other = getFloat();

   cout << endl;
   display(income, budgetLiving, actualLiving, tax, tithing, other);

   return 0;
}

            

            
       
      
