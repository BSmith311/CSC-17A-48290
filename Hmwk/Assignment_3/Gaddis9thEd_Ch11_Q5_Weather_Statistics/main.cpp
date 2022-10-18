/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 15
 * Purpose:  Yearly Weather Statistics
 *           This only works on Code-E
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    enum Months{January, Feburary, March, April,         //Months
                May, June, July, August, September,
                October, November, December};
    const int NUM_MONTHS=12;        //Number of months
    float rain[NUM_MONTHS],         //Rainfall
          highT[NUM_MONTHS],        //High temp
          lowT[NUM_MONTHS];         //Low temp
    float avgR, avgT,               //Average Rainfall, Average Temp
          highsT, lowsT;            //Highest Temp, Lowest Temp
    Months month;                   //Month counter
    //Initialize Variables
    highsT=-10000;                  //Placeholder value
    lowsT=10000;                    //Placeholder value
    avgR=avgT=0;                    //Placeholder value
    //Process or map Inputs to Outputs
    for (month=January; month<=December; month=static_cast<Months>(month+1)){   //Enum months loop
            while(cin>>rain[month]){    //Loops until there are no more inputs
            //Rainfall
            cout<<"Enter the total rainfall for the month:"<<endl;
            avgR+=rain[month];          //Adds rain to average rain
            //High Temp
            cout<<"Enter the high temp:"<<endl;
            cin>>highT[month];          //Inputs high temp
            avgT+=highT[month];         //Adds high temp to average
            if (highT[month]>highsT)highsT=highT[month];    //Highest temp check
            //Low Temp
            cout<<"Enter the low temp:"<<endl;
            cin>>lowT[month];           //Inputs low temp
            avgT+=lowT[month];          //Adds low temp to average
            if (lowT[month]<lowsT)lowsT=lowT[month];        //Lowest temp check
            }
    }
    //Calculate Averages
    avgR=(avgR*2)/month;
    avgT=avgT/month;
    //Display Outputs
    cout<<"Average monthly rainfall:"<<fixed<<setprecision(2)<<avgR<<endl;
    cout<<"High Temp:"<<fixed<<setprecision(0)<<highsT<<endl;
    cout<<"Low Temp:"<<fixed<<setprecision(0)<<lowsT<<endl;
    cout<<"Average Temp:"<<fixed<<setprecision(1)<<avgT;
    //Exit stage right!
    return 0;
}