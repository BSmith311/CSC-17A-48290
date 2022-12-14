/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 27, 2022
 * Purpose: Ch 15 Q1 Employee and ProductionWorker Classes
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
//#include "Employee.h"
#include "ProductionWorker.h"

//Execution
int main(int argc, char** argv) {
    //Declare variables
    string name, number, date, shift;
    int hours;
    float pay;
    
    //Get user inputs
    cout<<"Enter the employee's name: ";
    getline(cin, name);
    
    cout<<"Enter the employee's number: ";
    getline(cin, number);
    
    cout<<"Enter the employee's hire date: ";
    getline(cin, date);
    
    //Day or night shift
    cout<<"Was a day shift or night shift worked? (D/N): ";
    cin>>shift;
    cin.ignore();
    while (shift != "D" && shift != "d" && shift != "N" && shift != "n"){
        cout<<"Invalid input. Enter 'D' for a day shift or 'N' for night shift: ";
                cin>>shift;
                cin.ignore();
    }
    
    if (shift == "D" or shift == "d"){
        //Get hours worked and pay rate
        cout<<"Enter the day shift hours worked: ";
        cin>>hours;
        cin.ignore();
        while (hours < 0){
            cout<<"Invalid hours worked, cannot be negative."<<endl;
            cout<<"Enter the day shift hours worked: ";
            cin>>hours;
        }

        cout<<"Enter the day shift pay rate: ";
        cin>>pay;
        cin.ignore();
        while (pay < 0){
            cout<<"Invalid pay rate, cannot be negative."<<endl;
            cout<<"Enter the pay rate: ";
            cin>>pay;
        }
        
        //Create shift1 class instance
        ProductionWorker shift1(hours, pay);
        
        //Fill employee info
        shift1.setName(name);
        shift1.setNumber(number);
        shift1.setDate(date);
        
        //Output results
        cout<<endl<<"Employee Info:"<<endl;
        cout<<"Employee Name: "<<shift1.getName()<<endl;
        cout<<"Employee Number: "<<shift1.getNumber()<<endl;
        cout<<"Employee Hire Date: "<<shift1.getDate()<<endl;
        cout<<"Total Pay: $"<<fixed<<setprecision(2)<<(shift1.getPay()*shift1.getShift())<<endl;
    }else{
        cout<<"Enter the night shift hours worked: ";
        cin>>hours;
        cin.ignore();
        while (hours < 0){
            cout<<"Invalid hours worked, cannot be negative."<<endl;
            cout<<"Enter the night shift hours worked: ";
            cin>>hours;
        }

        cout<<"Enter the night shift pay rate: ";
        cin>>pay;
        cin.ignore();
        while (pay < 0){
            cout<<"Invalid pay rate, cannot be negative."<<endl;
            cout<<"Enter the pay rate: ";
            cin>>pay;
        }
        
        //Create shift1 class instance
        ProductionWorker shift2(hours, pay);
        
        //Fill employee info
        shift2.setName(name);
        shift2.setNumber(number);
        shift2.setDate(date);
        
        //Output results
        cout<<endl<<"Employee Info:"<<endl;
        cout<<"Employee Name: "<<shift2.getName()<<endl;
        cout<<"Employee Number: "<<shift2.getNumber()<<endl;
        cout<<"Employee Hire Date: "<<shift2.getDate()<<endl;
        cout<<"Total Pay: $"<<fixed<<setprecision(2)<<(shift2.getPay()*shift2.getShift())<<endl;
    }
    
    //Exit
        return 0;
}

