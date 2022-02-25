/*******************************
***  Assignment 3 Question 2 ***
******  by Peter Compton  ******
*******************************/


/**
 * This program will read 2 input files that provide data about certain employee types
 * within a business. Based on this data, the program will generate three reports. 
 * A weekly salary employee total pay report, a weekly hourly employee total pay report 
 * and a top performers report.
 */

#include "employee.h"
#include "hourlyEmployee.h"
#include "salaryEmployee.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes ----------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void reportPaySalary(salaryEmployee[], int);
void reportPayHourly(hourlyEmployee[], int);
double totalPaySalary(salaryEmployee[], int);
double totalPayHourly(hourlyEmployee[], int);
void topPerformers(hourlyEmployee[], int);
double totalTaxHourly(hourlyEmployee[], int);
// ------------------------------------------------------------------------------------------------

const int NUM_ROWS = 20; 


/** 
* The main function calls each of the other functions to control the sequence of the program.
*
*/
int main(int argc, char const *argv[]) {
  

  hourlyEmployee *hourly;
  salaryEmployee *salary;
  salary = new salaryEmployee[NUM_ROWS];  // Array created on the heap for dynamic memory allocation
  hourly = new hourlyEmployee[NUM_ROWS];  // Array created on the heap for dynamic memory allocation

  int salCount = 0;
  int hourCount = 0;

 // ------------------------------------------------------------------------------------------------
 /* This block of code will read the first input file and create class instances based on the first
 digit of the employees ID. Salary employees ID's start with a 1, hourly employees start with anything
 else. The class instances will have the ID, name and pay amounts set.
 */

  string file;
  file = "employee.txt";
  ifstream inFile;
  inFile.open(file);

  string ID, name, pay,idTest, hoursOrBonus;

  if (inFile.is_open()){  
    while(!inFile.eof()){  
      inFile >> ID >> name >> pay;
      if(ID[0] == '1'){
        salary[salCount].setID(ID);
        salary[salCount].setName(name);
        salary[salCount].setPay(stod(pay));
        salCount++;
      }
      else{
        hourly[hourCount].setID(ID);
        hourly[hourCount].setName(name);
        hourly[hourCount].setPay(stod(pay));
        hourCount++;
      }
    }
  }
  inFile.close();
 // ------------------------------------------------------------------------------------------------

 // ------------------------------------------------------------------------------------------------
 /* This block of code will read the second input file and update the hours worked for hourly
 employees and the performance bonus for salary employees.
 */

  string file2;
  file2 = "work.txt";
  ifstream inFile2;

  inFile2.open(file2);

  if (inFile2.is_open()){  
    while(!inFile2.eof()){  
      inFile2 >> idTest >> hoursOrBonus;
      if(idTest[0] == '1'){
        for(int i = 0; i < salCount; i++){         
          if(idTest == salary[i].getID()){
            salary[i].setBonus(stod(hoursOrBonus));
          }
        }
      }
      else{
        for(int j = 0; j < hourCount; j++){
          if(idTest == hourly[j].getID()){
            hourly[j].setHours(stod(hoursOrBonus));
          }
        }
      }
    }
  }
  inFile2.close();

  // ------------------------------------------------------------------------------------------------

  // Generate the three required reports
  reportPayHourly(hourly,hourCount);
  reportPaySalary(salary,salCount);
  topPerformers(hourly, hourCount);


  delete [] salary; // Delete the array from the heap
  delete [] hourly; // Delete the array from the heap

  return 0;
}


// Function Area -------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

/** 
* The reportPayHourly function generates a report that prints out the pay details of all
* hourly employees including the total pay ammount and the total tax payable
*
* @param array[] - a hourlyEmployee array that is searched to generate the report
* @param numEmployee - the number of employees to be listed in the report
*/
void reportPayHourly(hourlyEmployee array[], int numEmployee){
  cout << fixed;
  cout << "\n" << "Hourly Employee Pay Report" << endl; 
  cout << "\n" << "Empoyee ID" << "     " << "Name" << "     " << "Pay Per Hour" << "     " << "Hours Worked" << "     " << "Pay for Week" << endl;
  for(int i = 0; i < numEmployee; i++){
    cout << array[i].getID() << "            ";      
    cout << array[i].getName();
    for(int j = 0; j < 9.0 - array[i].getName().length(); j++){
      cout << " ";
    }
    cout << setprecision(2) << "$"  << array[i].getPay();
    for(int k = 0; k < 20.0 - to_string(array[i].getPay()).length(); k++){
      cout << " ";
    }
    cout << array[i].getHours() << "               ";
    cout << setprecision(2) <<"$" << array[i].computePay() << endl;
  }
  cout <<"\n"<<  "                                          " << "Total Pay Bill: $" << totalPayHourly(array, numEmployee) << endl;
  cout << "                                       " << "Total Tax Payable: $" << totalTaxHourly(array, numEmployee) << endl;
}

/** 
* The reportPaySalary function generates a report that prints out the pay details of all
* salary employees including the total pay ammount
*
* @param array[] - a salaryEmployee array that is searched to generate the report
* @param numEmployee - the number of employees to be listed in the report
*/
void reportPaySalary(salaryEmployee array[], int numEmployee){
  cout << fixed;
  cout << "\n" << "Salary Employee Pay Report" << endl; 
  cout << "\n" << "Empoyee ID" << "     " << "Name" << "     " << "Salary" << "           " << "Perf Bonus" << "       " << "Pay for Week" << endl;
  for(int i = 0; i < numEmployee; i++){
    cout << array[i].getID() << "            ";      
    cout << array[i].getName();
    for(int j = 0; j < 9.0 - array[i].getName().length(); j++){
      cout << " ";
    }
    cout << setprecision(2) << "$"  << array[i].getPay();
    for(int k = 0; k < 20.0 - to_string(array[i].getPay()).length(); k++){
      cout << " ";
    }
    cout << "$" << array[i].getBonus();
    for(int l = 0; l < 20.0 - to_string(array[i].getBonus()).length(); l++){
      cout << " ";
    }
    cout << setprecision(2) <<"$" << array[i].computePay() << endl;
  }
  cout <<"\n"<<  "                                         " << "Total Pay Bill - $" << totalPaySalary(array, numEmployee) << endl;
}

/** 
* The totalPaySalary uses the overloaded " + " symbol to calculate the total pay ammount
* for all salary employees
*
* @param array[] - a salaryEmployee array that is searched to calculate the total pay
* @param numEmployee - the number of employees 
* @return - the total pay for all salary employees
*/
double totalPaySalary(salaryEmployee array[], int numEmployee){
  double totalPay = 0.0;
  for(int i = 0; i < numEmployee; i+=2){
    totalPay += array[i].computePay() + array[i+1].computePay();
  } 
  return totalPay;
}

/** 
* The totalPayHourly function uses the overloaded " + " symbol to calculate the total pay 
* ammount for all hourly employees
*
* @param array[] - a hourlyEmployee array that is searched to calculate the total pay
* @param numEmployee - the number of employees 
* @return - the total pay for all hourly employees
*/
double totalPayHourly(hourlyEmployee array[], int numEmployee){
  double totalPay = 0.0;
  for(int i = 0; i < numEmployee; i+=2){
    totalPay +=  array[i].computePay() + array[i+1].computePay() ;
  } 
  return totalPay;
}


/** 
* The topPerformers function uses the bubble sort algorithm and the overloaded " > " 
* symbol to calculate the three top performers for the week. This is then used to 
* display the results in a report.
*
* @param array[] - a hourlyEmployee array that is searched to calculate the total pay
* @param numEmployee - the number of employees 
*/
void topPerformers(hourlyEmployee array[], int numEmployee){
  
  string ID;
  string name;
  double hours;
  double pay;

  for (int i = 0; i < numEmployee - 1; i++){
      for(int j = 0; j < numEmployee; j++){
        if(array[j+1] > (array[j])){

          // Triangular swap method
          ID = array[j+1].getID();
          name = array[j+1].getName();
          hours = array[j+1].getHours();
          pay = array[j+1].getPay();

          array[j+1].setID(array[j].getID());
          array[j+1].setName(array[j].getName());
          array[j+1].setHours(array[j].getHours());
          array[j+1].setPay(array[j].getPay());

          array[j].setID(ID);
          array[j].setName(name);
          array[j].setHours(hours);
          array[j].setPay(pay);
      }
    }
  }
  cout << fixed;
  cout << "\n" << "Weekly Top Performers Report" << endl << endl;
  cout << "Empoyee ID" << "     " << "Name" << "     " << "Pay for Week" << endl;

  for(int j = 0; j < 3; j++){
    cout << array[j].getID() << "            " << array[j].getName();
    for(int k = 0.0; k < 9.0 - array[j].getName().length(); k++){
      cout << " ";
    }
    cout << array[j].computePay() << endl;
  }
}

/** 
* The totalTaxHourly function calculates the total tax payable for all hourlyEmployees
*
* @param array[] - a hourlyEmployee array that is searched to calculate the total pay
* @param numEmployee - the number of employees 
* @return - The total pre-tax pay minus the total after tax pay = total tax
*/
double totalTaxHourly(hourlyEmployee array[], int numEmployee){
  double totalTax = 0.0;
  for(int i = 0; i < numEmployee; i+=2){
    totalTax += (array[i].computePay() + array[i+1].computePay()) - (array[i].totalPay() + array[i+1].totalPay()) ;
  } 
  return totalTax;
}