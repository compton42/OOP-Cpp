/*******************************
***  Assignment 3 Question 1 ***
******  by Peter Compton  ******
*******************************/

#include <iostream>
#include <string>
#include "Question1.h"

using namespace std;


// ---------------------------------------------------------------------------------------------
/** 
* The main function creates 4 conjecture objects and tests the given values for the number of
* recursive calls and the maximum value reached.
*/
int main(){

    conjecture test1 = conjecture(27);
    conjecture test2 = conjecture(837799);
    conjecture test3 = conjecture(75128138247);
    conjecture test4 = conjecture(942488749153153);

    test1.print();
    test2.print();
    test3.print();
    test4.print();

    return 0;
}



