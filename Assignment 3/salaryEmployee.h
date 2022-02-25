/*******************************
***  Assignment 3 Question 2 ***
*******  salaryEmployee  *******
*********  Header File  ********
******  by Peter Compton  ******
*******************************/

#include <iostream>
#include <string>
#include "employee.h"

class salaryEmployee : public employee
{
public:
   salaryEmployee();
   void setBonus(double);
   double getBonus();
   double computePay();
   double totalPay();
   bool operator>(salaryEmployee);
private:
   double performanceBonus;  
};

