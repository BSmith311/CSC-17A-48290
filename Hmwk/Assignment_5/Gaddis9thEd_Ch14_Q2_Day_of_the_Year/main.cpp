/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 14 Q2 Day of the Year
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "DayOfYear.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int x;
    
    //Get user input
    cout<<"Enter a day of the year (1-365): ";
    cin>>x;
    while (x < 1 or x > 365){
        cout<<"Invalid day, enter a number between 1 and 365: ";
        cin>>x;
    }
    
    //Define instance of DayOfYear Class
    DayOfYear day(x);
    
    //Call print function
    day.print();
    
    //Exit
        return 0;
}

void DayOfYear::print(){
    int m, d;
    
    if (day >= 1 && day < 32){
        m = 1;
        d = day;
    }
    else if (day >= 32 && day < 60){
        m = 2;
        d = day - 31;
    }
    else if (day >= 60 && day < 91){
        m = 3;
        d = day - 59;
    }
    else if (day >= 91 && day < 121){
        m = 4;
        d = day - 90;
    }
    else if (day >= 121 && day < 152){
        m = 5;
        d = day - 120;
    }
    else if (day >= 152 && day < 182){
        m = 6;
        d = day - 151;
    }
    else if (day >= 182 && day < 213){
        m = 7;
        d = day - 181;
    }
    else if (day >= 213 && day < 244){
        m = 8;
        d = day - 212;
    }
    else if (day >= 244 && day < 274){
        m = 9;
        d = day - 243;
    }
    else if (day >= 274 && day < 305){
        m = 10;
        d = day - 273;
    }
    else if (day >= 305 && day < 335){
        m = 11;
        d = day - 304;
    }
    else if (day >= 335 && day <= 365){
        m = 12;
        d = day - 334;
    }
    
    cout<<months[m-1]<<" "<<d;
}