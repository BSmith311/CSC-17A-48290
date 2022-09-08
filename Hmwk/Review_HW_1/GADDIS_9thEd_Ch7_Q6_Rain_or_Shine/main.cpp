/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 8, 2022
 * Purpose: Store and create a report to display weather conditions
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays
const int MONTHS=3;
const int DAYS=30;
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    string name[MONTHS]={"June",
                         "July",
                         "August"};
    char date[MONTHS][DAYS];
    ifstream weather;
    int month, day;            //Month and day counters
    int rain, cloud, sun;       //Rainy, cloudy, sunny counters
    int rainT=0;                //Total rainy days
    int cloudT=0;               //Total cloudy days
    int sunT=0;                 //Total sunny days
    int mostRainM;              //Month with most rain
    int mostRainT;              //Number of rainy days in rainiest month
    
    //Open File
    weather.open("RainOrShine.txt");
    if (!weather){          //File error check, ends program if true
        cout<<"Error opening data file."<<endl;
        return 0;
    }
    //Read weather data and record into array
    for (month=0;month<MONTHS;month++){
        for (day=0;day<DAYS;day++){
            weather>>date[month][day];
        }
    }
    //Close File
    weather.close();
    
    //Heading
    cout<<"     Summer Weather Report"<<endl
        <<"Month   Rainy   Cloudy   Sunny"<<endl
        <<"-------------------------------"<<endl;
    
    //Calculate weather results and display
    for (month=0;month<MONTHS;month++){
        rain=cloud=sun=0;       //Resets weather counters
        for (day=0;day<DAYS;day++){
            if (date[month][day]=='R')rain++;
            else if (date[month][day]=='C')cloud++;
            else sun++;
        }
        //Add to month weather totals
        rainT+=rain;
        cloudT+=cloud;
        sunT+=sun;
        //Rainiest month check
        if (rain>mostRainT){
            mostRainT=rain;
            mostRainM=month;
        }
        cout<<left<<setw(6)<<name[month]<<right
            <<setw(5)<<rain
            <<setw(9)<<cloud
            <<setw(8)<<sun<<endl;
    }
    
    //Display final results
    cout<<"-------------------------------"<<endl;
    cout<<"Totals:"<<setw(4)<<rainT
                   <<setw(9)<<cloudT
                   <<setw(8)<<sunT<<endl<<endl;
    cout<<name[mostRainM]<<" had the most rainy days."<<endl;
    //Exit stage right
        return 0;
}
