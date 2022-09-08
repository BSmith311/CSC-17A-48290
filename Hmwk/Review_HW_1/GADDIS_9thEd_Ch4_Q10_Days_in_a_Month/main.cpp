/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 6, 2022
 * Purpose: Check the days in a month in a set year
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
    int year;                   //Year
    unsigned int x, m[12];      //Months 1-12 (technically 13 but 0 is unused)
    //Initialize Variables
    m[1]=m[3]=m[5]=m[7]=m[8]=m[10]=m[12]=31;    //Months with 31 days
    m[4]=m[6]=m[9]=m[11]=30;                    //Months with 30 days
    //Map inputs to outputs -> The Process
    cout<<"Please enter the month (1-12):"<<endl;   //Input prompt
    cin>>x;                 //Month input
    while (x<1 || x>12){    //Input validation
        cout<<"Invalid month, please input a number between 1-12."<<endl;
        cin>>x;
    }
    cout<<"Please enter the year:"<<endl;           //Input prompt
    cin>>year;              //Year input
    while (year<0){         //Input validation
        cout<<"Invalid year, please input a positive number."<<endl;
        cin>>year;
    }
    
    //Leap year check
    if (year%100==0){
        if (year%400==0)m[2]=29;
        else m[2]=28;
    }
    else if (year%100!=0){
        if (year%4==0)m[2]=29;
        else m[2]=28;
    }
    
    //Display Results
    cout<<"Month "<<x<<" has "<<m[x]<<" days "  //Month and Days output
        <<"in the year "<<year<<"."<<endl;      //Year output
    //Exit stage right
        return 0;
}

