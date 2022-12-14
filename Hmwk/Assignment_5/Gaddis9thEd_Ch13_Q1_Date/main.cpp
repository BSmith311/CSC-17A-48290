/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 21, 2022
 * Purpose: Ch 13 Q1 Date
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Date.h"

//Execution
int main(int argc, char** argv) {
    //Define instance of Date Class
    Date date;
    
    //Declare Variables
    int month;
    int day;
    int year;
    
    //Get user inputs
    //Month
    cout<<"Enter the month: (1-12): ";
    cin>>month;
    while (month < 1 or month > 12){
        cout<<"Invalid input, month must be between 1 and 12: ";
        cin>>month;
    }
    
    //Day
    cout<<"Enter the day: (1-31): ";
    cin>>day;
    while (day < 1 or day > 31){
        cout<<"Invalid input, day must be between 1 and 31: ";
        cin>>day;
    }
    
    //Year
    cout<<"Enter the year: ";
    cin>>year;
    
    //Call class Mutators
    date.setDate(month,day,year);
    
    //Call class Accessors
    date.printDate1();
    date.printDate2();
    date.printDate3();
    
    //Exit
        return 0;
}

//Functions
void Date::setDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::printDate1(){
    cout<<endl<<month<<"/"<<day<<"/"<<year<<endl;
}

void Date::printDate2(){
    if (month == 1)cout<<"January ";
    else if (month == 2)cout<<"February ";
    else if (month == 3)cout<<"March ";
    else if (month == 4)cout<<"April ";
    else if (month == 5)cout<<"May ";
    else if (month == 6)cout<<"June ";
    else if (month == 7)cout<<"July ";
    else if (month == 8)cout<<"August ";
    else if (month == 9)cout<<"September ";
    else if (month == 10)cout<<"October ";
    else if (month == 11)cout<<"November ";
    else if (month == 12)cout<<"December ";
    
    cout<<day<<", "<<year<<endl;
}

void Date::printDate3(){
    cout<<day<<" ";
    
    if (month == 1)cout<<"January ";
    else if (month == 2)cout<<"February ";
    else if (month == 3)cout<<"March ";
    else if (month == 4)cout<<"April ";
    else if (month == 5)cout<<"May ";
    else if (month == 6)cout<<"June ";
    else if (month == 7)cout<<"July ";
    else if (month == 8)cout<<"August ";
    else if (month == 9)cout<<"September ";
    else if (month == 10)cout<<"October ";
    else if (month == 11)cout<<"November ";
    else if (month == 12)cout<<"December ";
    
    cout<<year<<endl;
}