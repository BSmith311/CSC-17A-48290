/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 28, 2022
 * Purpose: Ch 16 Q2 Time Format Exceptions
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "MilTime.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int hours;
    int seconds;
    
    //Define instance of MilTime
    MilTime time;
    
    //Get user inputs
    cout<<"Enter the military hour (0000-2359): ";
    cin>>hours;
    while ((hours % 100) > 59){
        cout<<"Last two digits invalid, cannot be more than 59: ";
        cin>>hours;
    }
    
    try
    {
        time.BadHour(hours);
        time.setHour(hours);
    }
    catch (string exceptionString)
    {
        cout<<exceptionString<<endl;
        exit(EXIT_FAILURE);
    }
    
    cout<<"Enter the seconds (0-59): ";
    cin>>seconds;
    
    try
    {
        time.BadSeconds(seconds);
        time.setSeconds(seconds);
    }
    catch (string exceptionString)
    {
        cout<<exceptionString<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Set time
    time.setTime();
    
    //Output Standard Time
    cout<<endl<<"Military Time: "<<setw(4)<<setfill('0')<<time.getHour()<<endl;
    cout<<"Standard Time: "<<setw(2)<<time.getStandHr()<<":"
                           <<setw(2)<<setfill('0')<<time.getMin()<<":"
                           <<setw(2)<<setfill('0')<<time.getSec();
    if (hours > 1159) cout<<" PM"<<endl;
    else cout<<" AM"<<endl;
    
    //Exit
        return 0;
}

