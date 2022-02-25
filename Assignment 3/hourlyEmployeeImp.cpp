/*******************************
***  Assignment 3 Question 2 ***
******   hourlyEmployee  *******
******  Class Definition  ******
******  by Peter Compton  ******
*******************************/

#include "hourlyEmployee.h"
#include "employee.h"
#include <iostream>
#include <string>

// defult constructor implementation
hourlyEmployee::hourlyEmployee() : employee() {
    empHoursWorked = 0;
    overTimeHours = 0;
    overTimePay = 0;
}

// ---------------------------------------------------------------------------------------------
/** 
* The setHours method sets the value of the private member empHoursWorked
* 
* @param hours - The value that empHoursWorked will be set to
*/
void hourlyEmployee::setHours(double hours){
    empHoursWorked = hours;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getHours method gets the private member variable empHoursWorked
* 
* @return - the value stored in empHoursWorked
*/
int hourlyEmployee::getHours(){
    return empHoursWorked;
}  

// ---------------------------------------------------------------------------------------------
/** 
* The getOT method calculates if the worker has done any overtime. If so, the overTimeHours
* member variable is updated.
* 
* @return - the value stored in overTimeHours
*/
int hourlyEmployee::getOT(){
    if (getHours() > 40){ 
        overTimeHours = getHours() - 40;
    }
    return overTimeHours;
}

// ---------------------------------------------------------------------------------------------
/** 
* The payOT method calculates the overtime pay for a hourlyEmployee.
* 
* @return - the value stored in overTimePay
*/
double hourlyEmployee::payOT(){
    overTimePay = getOT()*1.5*getPay();
    return overTimePay;
}

// ---------------------------------------------------------------------------------------------
/** 
* The computePay method is a virtual method, it calculates the total pay for a hourlyEmployee
* including the their overtime
* 
* @return - the hourlyEmployee pre-tax pay
*/
double hourlyEmployee::computePay(){
    if (getHours() > 40){ 
        return payOT() + 40 * getPay();
    }
    else{
        return getHours()*getPay();
    }
}

// ---------------------------------------------------------------------------------------------
/** 
* The totalPay method is a virtual method, in the hourlyEmployee class it returns the total pay
* including overtime minus the 33% tax ammount.
* 
* @return - the after tax value of a hourlyEmployee
*/
double hourlyEmployee::totalPay(){
    return computePay() - (computePay()*getTax1());
}

// ---------------------------------------------------------------------------------------------
/** 
* The operator> method is a virtual method that overloads the " > " symbol. It is used to test
* if an hourlyEmplyee objects totalPay value is greater then another hourlyEmployee objects.
* 
* @return - a boolean value, true if the hourlyEmployee objects totalPay value is greater than 
* the test objects.
*/
bool hourlyEmployee::operator>(hourlyEmployee test){
    return totalPay() > test.totalPay();
}
