/*******************************
***  Assignment 3 Question 2 ***
*******  salaryEmployee  *******
******  Class Definition  ******
******  by Peter Compton  ******
*******************************/

#include "salaryEmployee.h"
#include "employee.h"
#include <iostream>
#include <string>

// default constructor implementation
salaryEmployee::salaryEmployee() : employee() {
    performanceBonus = 0.0;
}

// ---------------------------------------------------------------------------------------------
/** 
* The setBonus method sets the value of the private member performanceBonus
* 
* @param hours - The value that performanceBonus will be set to
*/
void salaryEmployee::setBonus(double bonus){
    performanceBonus = bonus;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getBonus method gets the private member variable performanceBonus
* 
* @return - the value stored in performanceBonus
*/
double salaryEmployee::getBonus(){
    return performanceBonus;
}

// ---------------------------------------------------------------------------------------------
/** 
* The computePay method is a virtual method, it calculates the total pay for a salaryEmployee
* including the their performance bonus
* 
* @return - the salaryEmployee pre-tax pay
*/
double salaryEmployee::computePay(){
    return getPay() + getBonus();
}

// ---------------------------------------------------------------------------------------------
/** 
* The totalPay method is a virtual method, in the salaryEmployee class it returns the total pay
* including their bonus minus the 45% tax ammount.
* 
* @return - the after tax value of a salaryEmployee salary 
*/
double salaryEmployee::totalPay(){
    return computePay() - (computePay() * getTax2());
}

// ---------------------------------------------------------------------------------------------
/** 
* The operator> method is a virtual method that overloads the " > " symbol. It is used to test
* if a salaryEmployee objects totalPay value is greater then another salaryEmployee objects.
* 
* @return - a boolean value, true if the salaryEmployee objects totalPay value is greater than 
* the test objects.
*/
bool salaryEmployee::operator>(salaryEmployee test){
    return totalPay() > test.totalPay();
}
