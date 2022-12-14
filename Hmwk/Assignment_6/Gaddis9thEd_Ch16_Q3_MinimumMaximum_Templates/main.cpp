/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 28, 2022
 * Purpose: Ch 16 Q3 Minimum/Maximum Templates
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "MinMax.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int int1, int2;
    float float1, float2;
    char char1, char2;
    
    //Program Introduction
    cout<<"This program compares two inputs using templates."<<endl;
    cout<<"It will compare integers, floats, and chars."<<endl;
    
    //Integers
    //Get user inputs
    cout<<endl<<"Enter an integer value: ";
    cin>>int1;
    
    cout<<"Enter another integer value: ";
    cin>>int2;
    
    //Output results
    cout<<endl<<"The lesser value is: "<<min(int1, int2)<<endl;
    cout<<"The greater value is: "<<max(int1, int2)<<endl;
    
    //Floats
    //Get user inputs
    cout<<endl<<"Enter an float value: ";
    cin>>float1;
    
    cout<<"Enter another float value: ";
    cin>>float2;
    
    //Output results
    cout<<endl<<"The lesser value is: "<<min(float1, float2)<<endl;
    cout<<"The greater value is: "<<max(float1, float2)<<endl;
    
    //Chars
    //Get user inputs
    cout<<endl<<"Enter an character: ";
    cin>>char1;
    
    cout<<"Enter another character: ";
    cin>>char2;
    
    //Output results
    cout<<endl<<"The lesser value is: "<<min(char1, char2)<<endl;
    cout<<"The greater value is: "<<max(char1, char2)<<endl;
    
    //Exit
        return 0;
}

