/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 14 Q1 Numbers Class
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Numbers.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int x;
    
    //Get user inputs
    cout<<"Enter a number between 0 and 9999: ";
    cin>>x;
    while (x < 0 or x > 9999){
        cout<<"Invalid number, enter a number between 0 and 9999: ";
        cin>>x;
    }
    
    //Define instance of Numbers class
    Numbers number(x);
    
    //Call print function
    number.print();
    
    //Exit
        return 0;
}

//Functions
void Numbers::print(){
    int n = number;
    
    cout<<endl<<"English Translation: "<<endl;
    if (number >= 1000){
        cout<<lessThan20[(number/1000)]<<thousand;
        n = number%1000;
    }
    if (n >= 100){
        cout<<lessThan20[(n/100)]<<hundred;
        n = n%100;
    }
    if (n >= 20){
        cout<<moreThan20[(n/10)-2]<<" ";
        if (n%10 != 0)cout<<lessThan20[(n%10)];
    }
    else{
        if (number == 0) cout<<lessThan20[number];
        else if (n != 0) cout<<lessThan20[n];
    }
}