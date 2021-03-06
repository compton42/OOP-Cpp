/*******************************
***  Assignment 1 Question 3 ***
******  by Peter Compton  ******
*******************************/


/**
* This program calculates the number of dishes a pastry chef can cook in a given time period,
* when each dish requires additional time over the previous dish.
*
* @param aMinutes - the time taken to prepare the first dish
* @param bMinutes - the extra time required over the previous dish 
* @param tMinutes - the total time available to prepare all the dishes
* @param dishCount - the calculated number of dishes that can be prepared
* @param timeLeft - the time remaining after the last dish is prepared 
 */


#include <iostream>

using namespace std;


// Function Prototypes - -----------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
int getInput(string msg);

// ---------------------------------------------------------------------------------------------
/** 
* The main function calls each of the other functions to control the sequence of the output
*
*/
int main(){
    int aMinutes;
    int bMinutes;
    int tMinutes;
    int dishCount;
    int timeLeft;
   
    // Get input from the user for dish times
    aMinutes = getInput("Please enter the number of minutes to prepare the first dish: ");
   
    bMinutes = getInput("How many more minutes are required for the next dish? ");
    
    tMinutes = getInput("Enter the total time (in minutes) available to prepare all dishes: ");
   
    // Calculate number of dishes that can be made
    for (int i = aMinutes; i <= tMinutes; i += (aMinutes + (dishCount*bMinutes))){
        dishCount ++;
        timeLeft = tMinutes - i;
    }   

    // Output results 
    cout << "In " << tMinutes << " minutes the pastry cook can prepare " << dishCount << " dishes with " << timeLeft << " minutes \nunused." << endl;
    
    return 0;
}

// Function Area -------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
/** 
* The getInput function manages data input from the user
*
* @param msg - The output message displayed to the user 
* @return - an integer value that the user has provided
*/
int getInput(string msg){
    int dishTime;

    cout << msg;
    cin >> dishTime;
    if (cin.fail()){
        cout << "Invalid value, exiting program!" << endl;
        exit (2);
        }
    cout << endl;
    return dishTime;
}