/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 28, 2022
 * Purpose: Ch 16 Q5 Total Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Total.h"

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int number;
    
    //Get number of variables
    cout<<"Enter the number of variables you would like to enter: ";
    cin>>number;
    
    //Get variables
    cout<<"Enter "<<number<<" values: "<<endl;
    float sum = total<float>(number);
    
    //Output Results
    cout<<endl<<"The sum of the values is: "<<sum;
    
    //Exit
        return 0;
}

