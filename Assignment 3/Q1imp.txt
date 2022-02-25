/*******************************
***  Assignment 3 Question 1 ***
******  Class Definitions ******
******  by Peter Compton  ******
*******************************/

#include<iostream>
#include<string>
#include "Question1.h"

using namespace std;

// ---------------------------------------------------------------------------------------------
/** 
* The default constuctor sets the initial values of private members counter and highNum. The 
* conjecture function is then called passing in testNum.
*
* @param testNum - The value to test for conjecture
*/
conjecture::conjecture(unsigned long long int testNum){
    counter = 0;
    highNum = 0;
    testNumber = testNum; 
    startNum = testNumber;    
    conjectCalc(&testNum);
}

// Object destuctor ----------------------------------------------------------------------------
conjecture::~conjecture(){  
}

// ---------------------------------------------------------------------------------------------
/** 
* The getNum method returns the initial value being tested.
*
* @return - The iniatial test value
*/
unsigned long long int conjecture::getNum(){
    return startNum;
}

// ---------------------------------------------------------------------------------------------
/** 
* The incCounter method increments the private counter member variable
*
*/ 
void conjecture::incCounter(){
    int *countP = &counter;
    *countP = *countP + 1;
}

// ---------------------------------------------------------------------------------------------
/** 
* The getCounter method returns the current value of the private counter member variable.
*
* @return - The current value of the private counter member variable
*/
int conjecture::getCounter(){
    return counter;
}

// ---------------------------------------------------------------------------------------------
/** 
* The isHigher method tests if the current testNumber value is greater than the current highNum
* member variable. If true, highNum is set to testNumber.
*
* @return - the getHighNumber method is called which returns the highNum member variable
*/
unsigned long long int* conjecture::isHigher(unsigned long long int *testNum){
    if(*testNum > highNum){
        highNum = *testNum;
    }
    return getHighNum();
}

// ---------------------------------------------------------------------------------------------
/** 
* The getHighNum method returns the current highNum member variable
*
* @return - the value stored in highNum using the highP pointer
*/
unsigned long long int* conjecture::getHighNum(){
    unsigned long long int *highP = &highNum;
    return highP;
}

// ---------------------------------------------------------------------------------------------
/** 
* The conjectCalc method is a recursive method that will continue to call itself until testNum
* is equal to 1. The method will also call the incCounter and isHigher methods to calculate the
* number of recursive calls and the max value recorded.
*
* @return - a recursive call back to conjectCalc with a new *testNum value
*/
unsigned long long int* conjecture::conjectCalc(unsigned long long int *testNum){
    testNum = &testNumber;
    if(*testNum == 1){
        return getHighNum();
      
    }
    else{
        if(*testNum %2 == 0){
            *testNum = *testNum/2;
            isHigher(testNum);
            incCounter();
        }
        else{
            *testNum = (*testNum)*3+1;
            isHigher(testNum);
            incCounter();
        }   
    }
    return conjectCalc(testNum);
}

// ---------------------------------------------------------------------------------------------
/** 
* The print method outputs the starting test value, the number of recursive calls and the highest
* recorded value to the console. 
*
*/
void conjecture::print(){

    cout << endl << "Starting with " << getNum() << " it took " << getCounter() << " steps. The highest number achieved was " << *getHighNum() << "."<< endl;
}