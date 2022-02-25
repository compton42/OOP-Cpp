/*******************************
***  Assignment 3 Question 2 ***
*****  Employee Base Class *****
******  Class Definition  ******
******  by Peter Compton  ******
*******************************/

#include "employee.h"
#include <iostream>
#include <string>

// ---------------------------------------------------------------------------------------------
/** 
* The default constuctor sets the initial values of the private members.
* 
*/
employee::employee() {
empID = "000";
empName = "Joe Blob";
empSalary = 0.0;
//empHoursWorked = 0;
}

// ---------------------------------------------------------------------------------------------
/** 
* The setID method sets the value of the private member empID
* 
* @param ID - The value that empID will be set to
*/
void employee::setID(string ID){
    empID = ID;
}

// ---------------------------------------------------------------------------------------------
/** 
* The setName method sets the value of the private member empName
* 
* @param name - The value that empName will be set to
*/
void employee::setName(string name){
    empName = name;
}

// ---------------------------------------------------------------------------------------------
/** 
* The setPay method sets the value of the private member empSalary
* 
* @param payRate - The value that empSalary will be set to
*/
void employee::setPay(double payRate){
    empSalary = payRate;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getID method gets the private member variable empID
* 
* @return - the value stored in empID
*/
string employee::getID(){
    return empID;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getName method gets the private member variable empName
* 
* @return - the value stored in empName
*/
string employee::getName(){
    return empName;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getPay method gets the private member variable empSalary
* 
* @return - the value stored in empSalary
*/
double employee::getPay(){
    return empSalary;
}

// ---------------------------------------------------------------------------------------------
/** 
* The payRise method increaes the empSalary variable by a given percentage
* 
* @param percentRise - the percentage value to increase empSalary by
*/
void employee::payRise(int percentRise){
    empSalary += (empSalary*percentRise);
}

// ---------------------------------------------------------------------------------------------
/** 
* The computePay method is a virtual method, in the base employee class it just returns getPay()
* 
* @return - the value stored in empSalary
*/
double employee::computePay(){
    return getPay();
}

// ---------------------------------------------------------------------------------------------
/** 
* The totalPay method is a virtual method, in the base employee class it returns the empSalary
* value minus the 33% tax ammount.
* 
* @return - the after tax value of empSalary
*/
double employee::totalPay(){
    return computePay() - (computePay()*getTax1());
}

// ---------------------------------------------------------------------------------------------
/** 
* The getTax1 method gets the private member variable taxRate1
* 
* @return - the value stored in taxRate1
*/
double employee::getTax1(){
    return taxRate1;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getPay method gets the private member variable taxRate1
* 
* @return - the value stored in taxRate2
*/
double employee::getTax2(){
    return taxRate2;
}

// ---------------------------------------------------------------------------------------------
/** 
* The operator+ method overloads the " + " symbol. It is used to add 2 employee objects totalPay
* values together. 
* 
* @return - the sum of the two object totalPay values
*/
double employee::operator+(employee add){
    return totalPay() + add.totalPay();
}

// ---------------------------------------------------------------------------------------------
/** 
* The operator> method is a virtual method that overloads the " > " symbol. It is used to test
* if an objects totalPay value is greater then another objects.
* 
* @return - a boolean value, true if the objects totalPay value is greater than the test objects.
*/
bool employee::operator>(employee test){
    return totalPay() > test.totalPay();
}