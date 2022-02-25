/*******************************
***  Assignment 1 Question 4 ***
******  by Peter Compton  ******
*******************************/


/**
 * This program will output the inflation rate for two successive years and whether or not
 * the inflation is increasing, decreasing or remaining steady. This program requires user
 * input for the previous and current cost of an item to determine the inflation rates.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes -------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
double getInput (string msg);
double inflation(double oneYearPrice, double currentPrice);
void output (double year1, double year2);

// ---------------------------------------------------------------------------------------------
/** 
* The main function calls each of the other functions to control the sequence of the output
*
*/

int main(){
    double year1, preYear, prePreYear, currentInflation, pastInflation;

    // Get input from the user
    year1 = getInput ("Enter the current price of the item: ");
    preYear = getInput ("Enter the price of the item from one year ago: ");
    prePreYear = getInput ("Enter the price of the item from two years ago: ");

    // Calculate inflation
    currentInflation = inflation(preYear, year1);
    pastInflation = inflation(prePreYear, preYear);

    // Output results
    output (pastInflation,currentInflation);
   
    return 0;
}


// Function Area -------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
/** 
* The getInput function manages data input from the user
*
* @param msg - The output message displayed to the user 
* @return - a double currency value that the user has provided
*/
double getInput (string msg){
    double price;
    cout << fixed << setprecision(2);
    cout << msg;
    cin >> price;
    if (cin.fail()){
        cout << "Invalid value, exiting program!" << endl;
        exit (2);
    }
    cout << endl;   
    return price;
}

// ----------------------------------------------------------------------------------------------
/** 
* The inflation function calculates the inflation between two years
*
* @param previousYear - The value of an item in the previous year
* @param currentPrice - The current value of the item
* @return - the calculated inflation
*/
double inflation(double previousPrice, double currentPrice){
    double calcInflation;

    calcInflation = (currentPrice - previousPrice)/previousPrice;
    return calcInflation;
}

// ----------------------------------------------------------------------------------------------
/** 
* The output function displays the calculated inflation rates and the direction of inflation
*
* @param pastInflation - the past inflation rate
* @param currentInflation - the current inflation rate
*/
void output (double pastInflation, double currentInflation){
    cout << "The current years inflation rate is: " << currentInflation << endl;
    cout << "The inflation one year ago was: " << pastInflation << endl;

    // Check direction of inflation
    if (currentInflation > pastInflation){
        cout << "Inflation is increasing." << endl;
    }
    else if (currentInflation < pastInflation){
        cout << "Inflation is decreasing." << endl;
    }
    else{
        cout << "Inflation has remained steady." << endl;
    }
}