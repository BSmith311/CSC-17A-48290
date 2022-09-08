/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 6, 2022
 * Purpose: Convert USD to Yen and Euros
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays
const float YEN_CONVERSION=143.40;      //Yen conversion
const float EUROS_CONVERSION=1.01;      //Euros conversion
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float usd, yen, euro;       //US Dollars, Yen, and Euros variables
    //Initialize Variables
    cout<<"Please enter the amount of US dollars."              //Input Prompt
        <<"The program will convert it to Yen and Euros."<<endl;
    cin>>usd;                   //USD input
    //Map inputs to outputs -> The Process
    yen=(usd*YEN_CONVERSION);   //Yen conversion
    euro=(usd*EUROS_CONVERSION);//Euros conversion
    
    //Yen and Euro Worth Output
    cout<<endl<<"1 US Dollar is equivalent to "
        <<fixed<<setprecision(2)<<YEN_CONVERSION<<" Yen or "
        <<fixed<<setprecision(2)<<EUROS_CONVERSION<<" Euros."<<endl<<endl;
    //Final Results
    cout<<fixed<<setprecision(2)<<usd<<" US Dollars is equal to:"<<endl
        <<fixed<<setprecision(2)<<yen<<" Yen."<<endl
        <<fixed<<setprecision(2)<<euro<<" Euros"<<endl;
    //Exit stage right
        return 0;
}

