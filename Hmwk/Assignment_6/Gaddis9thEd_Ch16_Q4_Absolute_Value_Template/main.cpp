/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 28, 2022
 * Purpose: Ch 16 Q4 Absolute Value Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "AbsoluteValue.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int x;
    float y;
    
    //Program Introduction
    cout<<"This program will return the absolute value of the input."<<endl;
    
    //Integer
    //Get user input
    cout<<endl<<"Enter an integer value: ";
    cin>>x;
    
    //Output Results
    cout<<"The absolute value is: "<<abs(x)<<endl;
    
    //Float
    //Get user input
    cout<<endl<<"Enter a float value: ";
    cin>>y;
    
    //Output Results
    cout<<"The absolute value is: "<<abs(y)<<endl;
    
    //Exit
        return 0;
}

