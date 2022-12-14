/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 13 Q3 Car Class
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Car.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int y;
    string m;
    
    //Get user inputs
    cout<<"Enter the car's year model: ";
    cin>>y;
    cin.ignore();
    cout<<"Enter the car's make: ";
    getline(cin, m);
    cout<<endl;
    
    //Define instance of Car Class and fill with constructor
    Car car(y,m);
    
    //Call the accelerate function 5 times and display speed
    cout<<"Calling the accelerate function:"<<endl;
    for (int i=0; i<5; i++){
        car.accelerate();
        cout<<car.getMake()<<" "<<car.getYearModel()<<" Current Speed: "<<car.getSpeed()<<" mph"<<endl;
    }
    cout<<endl;
    
    //Call the brake function 5 times and display speed
    cout<<"Calling the brake function:"<<endl;
    for (int i=0; i<5; i++){
        car.brake();
        cout<<car.getMake()<<" "<<car.getYearModel()<<" Current Speed: "<<car.getSpeed()<<" mph"<<endl;
    }
    
    //Exit
        return 0;
}

