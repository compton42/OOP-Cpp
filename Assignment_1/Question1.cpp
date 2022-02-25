/*******************************
***  Assignment 1 Question 1 ***
******  by Peter Compton  ******
*******************************/


/**
 * This program uses a file stream to read numbers from a file and calculate if those numbers  
 * are a palindrome. The results are then displayed in the console window.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Function Prototypes - -----------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
bool numberPalindrome(double testNum);
void output(double testNum);

// ---------------------------------------------------------------------------------------------
/** 
* The main function calls each of the other functions to control the sequence of the output
*
*/
int main(){
    string file;
    string testLine;
    double testNum;
    file = "numbers.txt";
    int counter;

    ifstream inFile;

    // Open numbers.txt
    inFile.open(file);

    // Check if file opened
    if (inFile.is_open()){  

        // Check for end of file flag
        while(!inFile.eof()){    
            getline(inFile,testLine);
            testNum = stod(testLine,NULL);
            if(numberPalindrome(testNum)){
                output(testNum);
                counter ++;
                }
            }  
        }

    inFile.close();
    cout << "\nA total of " << counter << " palindromic numbers were found."<< endl; 
    return 0;
}

// Function Area -------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
/** 
* The numberPalindrome function tests to determine if a given number is a palindrome or not
* by reversing the sequence of the given number and testing if the number provided and the
* reversed number are the same.
*
* @param testNum - the number to be tested 
* @return - a boolean value, true if the number is palindromic, false if it is not
*/
bool numberPalindrome(double testNum){
    long long int number; 
    int remainder;
    long long int reverseNum;
    long long int count;

    number = testNum/1;
    count = number;

    while(count != 0){
        remainder = count %10;
        reverseNum = reverseNum * 10 + remainder;
        count /= 10;
    }
    return (reverseNum == number);
}

// ----------------------------------------------------------------------------------------------
/** 
* The output function displays the palindromic number in the console terminal
*
* @param testNum - the tested number to be displayed to the console terminal 
*/
void output(double testNum){
    cout << fixed << setprecision(0) << endl;
    cout << "Number: " << testNum << " is a palindromic number." << endl;
}
