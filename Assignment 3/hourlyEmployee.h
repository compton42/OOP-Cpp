/*******************************
***  Assignment 3 Question 2 ***
*******  hourlyEmployee  *******
*********  Header File  ********
******  by Peter Compton  ******
*******************************/

#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

//derived class from employee base class
class hourlyEmployee : public employee {
  public:
    hourlyEmployee(); // default constructor
    void setHours(double);
    int getHours();
    int getOT();
    double payOT();
    double computePay();
    double totalPay();
    bool operator>(hourlyEmployee);

  private:
    int empHoursWorked;
    int overTimeHours;
    double overTimePay;
};


