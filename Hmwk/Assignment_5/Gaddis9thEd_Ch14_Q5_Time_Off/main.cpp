/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 14 Q5
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "TimeOff.h"

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int ms, st, mv, vt, mu, ut, num;
    string n;
    
    //Get user inputs
    cout<<"Enter the employee name: ";
    getline(cin, n);
    
    cout<<"Enter the employee identification number: ";
    cin>>num;
    cin.ignore();
    
    cout<<endl<<"Enter the max number of sick days that can be taken: ";
    cin>>ms;
    cin.ignore();
    
    cout<<"Enter the number of sick days taken: ";
    cin>>st;
    cin.ignore();
    
    cout<<endl<<"Enter the max number of vacation days that can be taken: ";
    cin>>mv;
    cin.ignore();
    while (mv > 240){
        cout<<"Company policy states an employee may not accumulate "
              "more than 240 hours of paid vacation."<<endl;
        cout<<"Enter an amount under 240 hours: ";
        cin>>mv;
        cin.ignore();
    }
    
    cout<<"Enter the number of vacation days taken: ";
    cin>>vt;
    cin.ignore();
    
    cout<<endl<<"Enter the max number of unpaid days that can be taken: ";
    cin>>mu;
    cin.ignore();
    
    cout<<"Enter the number of unpaid days taken: ";
    cin>>ut;
    cin.ignore();
    
    //Define instance of TimeOff Class
    TimeOff employee(ms,st,mv,vt,mu,ut,n,num);
    
    //Output Results
    cout<<endl<<"Employee Name: "<<employee.getName()<<endl;
    cout<<"Employee Identification Number: "<<employee.getNumber()<<endl;
    cout<<"Sick days taken: "<<employee.getSickTaken()<<endl;
    cout<<"Vacation days taken: "<<employee.getVacTaken()<<endl;
    cout<<"Unpaid days taken: "<<employee.getUnpaidTaken()<<endl<<endl;
    employee.PrintWarnings();
    
    //Exit
        return 0;
}

//Functions
void TimeOff::PrintWarnings(){
    if (sickTaken > maxSickDays) cout<<"Warning! Days of sick leave exceeded!"<<endl;
    else cout<<(maxSickDays-sickTaken)<<" sick days remaining."<<endl;
    
    if (vacTaken > maxVacation) cout<<"Warning! Number of vacation days exceeded!"<<endl;
    else cout<<(maxVacation-vacTaken)<<" vacation days remaining."<<endl;
    
    if (unpaidTaken > maxUnpaid) cout<<"Warning! Days of unpaid leave exceeded!"<<endl;
    else cout<<(maxUnpaid-unpaidTaken)<<" unpaid days remaining."<<endl;
}