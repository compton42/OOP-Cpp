/*******************************
***  Assignment 3 Question 2 ***
***********  employee  *********
*********  Header File  ********
******  by Peter Compton  ******
*******************************/

#ifndef H_WorkerType
#define H_WorkerType
#include <iostream>
#include <string>

using namespace std;

const int WORK_HOURS = 40;

class employee {
  public:
    employee();
    void setID(string);
    void setName(string);
    void setPay(double);
    string getID();
    string getName();
    double getPay();
    void payRise(int);
    virtual double computePay();
    virtual double totalPay();
    double operator+(employee);
    virtual bool operator>(employee);
    double getTax1();
    double getTax2();

  private:
    string empID;
    string empName;
    double empSalary;
    const double taxRate1 = 0.33;
    const double taxRate2 = 0.45;
    double grossPay;
    double netPay;
};

#endif