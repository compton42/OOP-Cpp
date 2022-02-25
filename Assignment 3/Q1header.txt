/*******************************
***  Assignment 3 Question 1 ***
********** Header File *********
******  by Peter Compton  ******
*******************************/

#ifndef QUESTION1_H
#define QUESTION1_H

#include<iostream>
#include <string> 
using namespace std;

class conjecture{

public:
    unsigned long long int* getHighNum();
    int getCounter();
    void incCounter();
    unsigned long long int getNum();
    unsigned long long int* isHigher(unsigned long long int*);
    unsigned long long int* conjectCalc(unsigned long long int*);
    void print();
  
    conjecture(unsigned long long int);  // Default constructor
    ~conjecture();   // Destructor

private:
    int counter;
    unsigned long long int highNum;
    unsigned long long int testNumber;
    unsigned long long int startNum;
};

#endif