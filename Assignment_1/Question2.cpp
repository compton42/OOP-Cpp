/*******************************
***  Assignment 1 Question 2 ***
******  by Peter Compton  ******
*******************************/


/**
 * This program looks at a range of numbers and determines which of those number are either
 * Prime Numbers, Armstrong Numbers or both. The program uses a file stream to write the 
 * results into a text file named output.txt. The results are displayed in a table, the 
 * table formatting can be modified if required in the border and createRow functions.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

// Function Prototypes - -----------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
void border(int numColumns, int columnWidth);
void createRow(string heading, string heading2, string heading3, int columnWidth);
bool isPrime(int testNum);
bool isArmstrong(int testNum);
void fileWrite(string text);

// ---------------------------------------------------------------------------------------------
/** 
* The main function calls each of the other functions to control the sequence of the output
*
*/
int main(){
    int columnWidth, columnNumber, primeCount, armstrongCount, bothCount, startNum, endNum;
    string number, start, end, countP,countA, countB;

    columnWidth = 16;
    columnNumber = 3;
    primeCount = 0;
    armstrongCount = 0;
    bothCount = 0;
    startNum = 100;
    endNum = 500;
    start = to_string(startNum);
    end = to_string(endNum);

    // Draw the table heading
    border(columnNumber,columnWidth);
    createRow("Number","Prime","Armstrong",columnWidth);
    border(columnNumber,columnWidth);

    // Draw the body of the table
    for(int i=startNum; i<=endNum; i++){ 

        // Input validation
        if(startNum < 100 || endNum > 999){             
            cout << "The test number is outside the vaild range"<< endl;
            exit(1);
        }

        // Test for both Prime and Armstrong Numbers
        if(isPrime(i) && isArmstrong(i)){
            number = to_string(i);
            createRow(number," X ","    X ",columnWidth);
            border(columnNumber,columnWidth);  
            primeCount++;
            armstrongCount++;
            bothCount++;
        } 

        // Test for Prime Number
        else if(isPrime(i)){
            number = to_string(i);
            createRow(number," X "," ",columnWidth);
            border(columnNumber,columnWidth);
            primeCount++;
          }

        // Test for Armstrong Number
        else if(isArmstrong(i)){
            number = to_string(i);
            createRow(number,"  ","    X ",columnWidth);
            border(columnNumber,columnWidth);
            armstrongCount++;
        }
    }
    
    // Output information about the number of Prime and Armstrong numbers
    countP = to_string(primeCount);
    countA = to_string(armstrongCount);
    countB = to_string(bothCount);

    fileWrite("\nBetween "+start+" and "+end+", "+countP+" Prime numbers were found.");
    fileWrite("\nBetween "+start+" and "+end+", "+countA+" Armstrong numbers were found.");
    fileWrite("\nBetween "+start+" and "+end+", "+countB+" numbers were both Prime and Armstrong numbers.");
    return 0;
}

// Function Area -------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
/** 
* The border function draws the row border for each row in the output table
*
* @param numColumns - Sets the number of columns in the table, for this question it is set to 3
* @param columnWidth - Sets the character width of the cell, for formatting the min value is 12
*/
void border(int numColumns, int columnWidth){
    string lineStyle;
    string lineFormat;
    lineFormat = "-";
    lineStyle = lineFormat;
    numColumns = 3;
    string corner = "+";

    if(columnWidth <12){
        columnWidth = 12;
    }

    for(int i=1; i<columnWidth; i++){
      lineStyle.append(lineFormat);
    }
    for (int j=1; j<=numColumns; j++){
    fileWrite(corner+lineStyle);
    }
    fileWrite(corner + "\n");
}

// ---------------------------------------------------------------------------------------------
/** 
* The createRow function inserts data into the rows and draws the inner cells
*
* @param heading - The string entered int the first cell
* @param heading2 - The string entered into the second cell
* @param heading3 - The string entered into the third cell
* @param columnWidth - Sets the character width of the cell, for formatting the min value is 12
*/
void createRow(string heading, string heading2, string heading3, int columnWidth){

    int widthCol1, widthCol2, widthCol3;
    string edgeChar;
    edgeChar = "|";

    if(columnWidth <12){   // Sets the minimum columnwidth to 12 characters
        columnWidth = 12;
    }
    // The column width must be adjusted to compensate for the string inserted
    widthCol1 = columnWidth - heading.length()+1;
    widthCol2 = columnWidth*2 - (heading.length()+heading2.length())+1;
    widthCol3 = columnWidth*3 - (heading.length()+heading2.length()+heading3.length())+1;

    // Create the first cell
    for(int i=1; i<=widthCol1; i++){
         if(i == 1 || i == widthCol1){
            fileWrite(edgeChar);
        }
        if(i != 1 || i != columnWidth/3 || i != widthCol1){
            fileWrite(" ");
        }
        if(i== columnWidth/3){
            fileWrite(heading);
        }
    }
    // Create the second cell
    for(int i = widthCol1; i <= widthCol2; i++){

        if(i == widthCol2){
            fileWrite(edgeChar);
        }
        if(i != widthCol1+columnWidth/3){
            fileWrite(" ");
          }
        if(i == widthCol1 + columnWidth/3){
            fileWrite(heading2);
          }
    }
    // Create the third cell
    for(int i = widthCol2; i <= widthCol3; i++){
         if(i == widthCol3){
            fileWrite(edgeChar);
        }
        if(i != widthCol2 + columnWidth/3-2){
            fileWrite(" ");
        }
        if(i == widthCol2 + columnWidth/3-2){
            fileWrite(heading3);
          }   
    }
    fileWrite("\n");
}
// ---------------------------------------------------------------------------------------------
/** 
* The isPrime function tests to determines if a given number is a Prime number or not
*
* @param testNum - The number to be tested if it is Prime or not
* @return - a boolean value, true if the number is Prime, false if it is not
*/
bool isPrime(int testNum){
    int counter;
    counter = 0;
    if(testNum <= 1){
        cout << "The number entered is not a Prime Number" << endl;
    }
    for(int i = 2; i <testNum;i++){
            if(testNum % i == 0){
                counter++;
            }
        }
    return (counter == 0);   
}

// ---------------------------------------------------------------------------------------------
/** 
* The isArmstrong function tests to determines if a given number is a Armstrong number or not
*
* @param testNum - The number to be tested if it is a Armstrong number
* @return - a boolean value, true if the number is Armstrong, false if it is not
*/
bool isArmstrong(int testNum){
    int num1;
    int num2;
    int num3;

    num1 = testNum/100;
    num2 = (testNum/10)%10;
    num3 = testNum%10;

    return  ((pow(num1,3)+pow(num2,3)+pow(num3,3)) == testNum);
}

// ----------------------------------------------------------------------------------------------
/** 
* The fileWrite function controls the information written to the output.txt file
*
*/
void fileWrite(string text){
    ofstream outFile;
    outFile.open("output.txt",ios::out|ios::app);
    outFile << text;
    outFile.close();
}

