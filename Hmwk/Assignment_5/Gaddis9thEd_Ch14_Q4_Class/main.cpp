/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 14 Q4
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "NumDays.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    float h1, h2;
    
    //Get user input
    cout<<"Enter the first number of work hours: ";
    cin>>h1;
    while (h1 < 0){
        cout<<"Hours worked must be positive: ";
        cin>>h1;
    }
    
    cout<<"Enter the second number of work hours: ";
    cin>>h2;
    while (h2 < 0){
        cout<<"Hours worked must be positive: ";
        cin>>h2;
    }
    
    //Define instance of NumDays
    NumDays num1(h1);
    NumDays num2(h2);
    
    //Call Mutator
    num1.setDays();
    num2.setDays();
    
    //Initial Outputs
    cout<<endl<<"Hours Worked (1): "<<num1.getHours()<<endl;
    cout<<"Days Worked (1): "<<num1.getDays()<<endl;
    
    cout<<endl<<"Hours Worked (2): "<<num2.getHours()<<endl;
    cout<<"Days Worked (2): "<<num2.getDays()<<endl;
    
    //Addition
    cout<<endl<<"Total Hours: "<<num1.Addition(h1,h2)<<endl;
    
    //Subtraction
    if (h1 > h2){
        cout<<endl<<"First Hours minus Second Hours: ";
        cout<<num1.Subtraction(h1,h2)<<endl;
    }
    
    else{
        cout<<endl<<"Second Hours minus First Hours: ";
        cout<<num2.Subtraction(h2,h1)<<endl;
    }
    
    //Increment
    cout<<endl<<"Incremented hours:"<<endl;
    num1.Increment();
    num1.setDays();
    num2.Increment();
    num2.setDays();
    
    cout<<endl<<"Hours Worked (1): "<<num1.getHours()<<endl;
    cout<<"Days Worked (1): "<<num1.getDays()<<endl;
    
    cout<<endl<<"Hours Worked (2): "<<num2.getHours()<<endl;
    cout<<"Days Worked (2): "<<num2.getDays()<<endl;
    
    num1.Decrement();
    num2.Decrement();
    
    //Decrement
    cout<<endl<<"Decremented hours:"<<endl;
    num1.Decrement();
    num1.setDays();
    num2.Decrement();
    num2.setDays();
    
    cout<<endl<<"Hours Worked (1): "<<num1.getHours()<<endl;
    cout<<"Days Worked (1): "<<num1.getDays()<<endl;
    
    cout<<endl<<"Hours Worked (2): "<<num2.getHours()<<endl;
    cout<<"Days Worked (2): "<<num2.getDays()<<endl;
    
    
    //Exit
        return 0;
}

