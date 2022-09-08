/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 6, 2022
 * Purpose: Predict the population size of organisms
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes
void popCalc(int&,int,float);               //Population calculation function
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int pop, days;                     //Initial population, days
    float popInc;                       //Population increase
    
    //Initialize Variables
    cout<<"This program predicts of size of a population of organisms."<<endl<<endl;
    
    //Starting Organisms
    cout<<"Please enter the starting number of organisms:"<<endl;
    cin>>pop;
    while (pop<2){
        cout<<"Starting population must be at least 2, please enter a new value."<<endl;
        cin>>pop;
    }
    
    //Population increase
    cout<<"Please enter the population increase as a percentage."<<endl;
    cin>>popInc;
    while (popInc<0){
        cout<<"Population increase must be positive, please enter a new value."<<endl;
        cin>>popInc;
    }
    popInc*=0.01;
    
    //Days of reproduction
    cout<<"Please enter the number of days the organisms will reproduce."<<endl;
    cin>>days;
    while (days<1){
        cout<<"Days of reproduction must be at least 1, please enter a new value."<<endl;
        cin>>days;
    }
    
    //Map inputs to outputs -> The Process
    
    //Display Results
    popCalc(pop,days,popInc);      //Calls population function
    cout<<endl<<"The final population is "<<pop<<endl;
    //Exit stage right
        return 0;
}

void popCalc(int& pop,int days,float popInc){
    for (int i=1; i<=days; i++){
        pop+=(pop*popInc);
        cout<<"Day: "<<i<<endl
        <<" Current population: "<<pop<<endl;
    }
}