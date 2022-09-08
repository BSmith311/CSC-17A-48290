/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 6, 2022
 * Purpose: Convert Celsius to Fahrenheit
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float c, f;             //Celsius and Fahrenheit variables
    //Initialize Variables
    cout<<"Please enter the temperature in Celsius "
        <<"and the program will convert it to Fahrenheit."<<endl; //Input prompt
    cin>>c;                 //Celsius input
    //Map inputs to outputs -> The Process
    f=(1.8*c+32);           //Fahrenheit Calculation
    //Display Results
    cout<<fixed<<setprecision(1)<<c<<" degrees Celsius is "          //Output
        <<fixed<<setprecision(1)<<f<<" degrees Fahrenheit."<<endl;   //Output
    //Exit stage right
        return 0;
}

