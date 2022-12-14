/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on August 23, 2022
 * Purpose: Ch 14 Q3 Day of the Year Modification
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

//User Libraries
#include "DayOfYear.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    string m;
    int d;
    
    //Get user input
    cout<<"Enter a month: ";
    cin>>m;
    while (m != "January" && m != "February" && m != "March" && m != "April" &&
           m != "May" && m != "June" && m != "July" && m != "August" &&
           m != "September" && m != "October" && m != "November" && m != "December"){
        cout<<"Invalid month, make sure spelling and capitalization is correct.";
        exit (EXIT_FAILURE);
    }
    
    cout<<"Enter a day of the month: ";
    cin>>d;
    
    if (m == "January" or m == "March" or m == "May" or m == "July" or 
        m == "August" or m == "October" or m == "December"){
        while (d < 1 or d > 31){
            cout<<"Day entered is outside the range of days for the given month.";
            exit (EXIT_FAILURE);
        }
    }else if (m == "February"){
        while (d < 1 or d > 28){
            cout<<"Day entered is outside the range of days for the given month.";
            exit (EXIT_FAILURE);
        }
    }else{
        while (d < 1 or d > 30){
            cout<<"Day entered is outside the range of days for the given month.";
            exit (EXIT_FAILURE);
        }
    }
    
    //Define instance of DayOfYear Class
    DayOfYear day(m,d);
    
    //Call print function
    day.print();
    
    //Exit
        return 0;
}

void DayOfYear::print(){
    cout<<"Month: "<<month<<endl;
    cout<<"Day: "<<day<<endl;
    
    //Increment
    cout<<endl<<"Next Day:"<<endl;
    int i = 0;
    day++;
    
    if (month == "January" or month == "March" or month == "May" or month == "July" or
        month == "August" or month == "October" or month == "December"){
        if (day == 32){
            while (months[i] != month){
                i++;
            }
            i++;
            cout<<"Month: "<<months[i%12]<<endl;
            cout<<"Day: 1"<<endl;
        }else{
            cout<<"Month: "<<month<<endl;
            cout<<"Day: "<<day<<endl;
        }
    }else if (month == "February"){
        if (day == 29){
            while (months[i] != month){
                i++;
            }
            cout<<"Month: "<<months[++i]<<endl;
            cout<<"Day: 1"<<endl;
        }else{
            cout<<"Month: "<<month<<endl;
            cout<<"Day: "<<day<<endl;
        }
    }else{
        if (day == 31){
            while (months[i] != month){
                i++;
            }
            cout<<"Month: "<<months[++i]<<endl;
            cout<<"Day: 1"<<endl;
        }else{
            cout<<"Month: "<<month<<endl;
            cout<<"Day: "<<day<<endl;
        }
    }
    day--;
    
    //Decrement
    cout<<endl<<"Previous Day:"<<endl;
    day--;
    
    if (day != 0){
        cout<<"Month: "<<month<<endl;
        cout<<"Day: "<<day<<endl;
    }else{
        int j = 0;
        while (months[j] != month){
            j++;
        }
        if (j != 0){
            cout<<"Month: "<<months[--j]<<endl;
            if (j == 0 or j == 2 or j == 4 or j == 6 or 
                j == 7 or j == 9 or j == 11) cout<<"Day: 31"<<endl;
            else if (j == 1) cout<<"Day: 28"<<endl;
            else cout<<"Day: 30"<<endl;
        }else{
            j = 11;
            cout<<"Month: "<<months[j]<<endl;
            cout<<"Day: 31"<<endl;
        }
    }
}