/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 8, 2022
 * Purpose: Display Fahrenheit to Celsius conversion from 1-20
 *          Convert user input from F to C
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes
float celsius(float);       //Conversion function
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float f, i;             //Fahrenheit, counter
    char choice;            //User choice
    //Initialize Variables
    i=1;
    //Conversion table header
    cout<<"This program converts Fahrenheit to Celsius."<<endl;
    cout<<"To begin, it will show the conversion from 1-20"<<endl;
    cout<<"F:   1      2      3      4      5      6      7      8      9      10     "
        <<"11     12     13     14    15    16    17    18    19    20"<<endl;
    cout<<"C:";
    //Loop to display conversions
    while(i<=20){
        cout<<fixed<<setprecision(2)<<celsius(i)<<" ";
        i++;
    }
    cout<<endl;
    //User Conversions
    do{
        cout<<endl<<"Please enter a value to convert."<<endl;
        cin>>f;
        cout<<f<<" degrees Fahrenheit is equal to "
            <<fixed<<setprecision(2)<<celsius(f)<<" degrees Celsius."<<endl;
        cout<<"Enter Y or y if you would like to convert another value, "
            <<"all other inputs will end the program."<<endl;
        cin>>choice;
    }while(choice=='Y' or choice=='y');
    
    //Exit stage right
        return 0;
}

float celsius(float f){    //Converts Fahrenheit to Celsius
    float c;
    c=((f-32)*5/9);
    return c;
}