/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 28, 2022
 * Purpose: Ch 15 Q4 Time Format
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
    
    //Get user inputs
    cout<<"Enter the military hours (0000-2359): ";
    cin>>hours;
    while (hours < 0 or hours > 2359 or (hours % 100) > 59){
        if (hours % 100 > 59){
            cout<<"Last two digits invalid, cannot be more than 59: ";
            cin>>hours;
        }else{
            cout<<"Invalid time, must be between 0000 and 2359: ";
            cin>>hours;
        }
    }
    
    cout<<"Enter the seconds (0-59): ";
    cin>>seconds;
    while (seconds < 0 or seconds > 59){
        cout<<"Invalid seconds, must be between 0 and 59: ";
        cin>>seconds;
    }
    
    //Define instance of MilTime
    MilTime time(hours, seconds);
    
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

