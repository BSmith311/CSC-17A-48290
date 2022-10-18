/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 11, 2022
 * Purpose: Corporate Sales Data Output
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Structure Declaration
struct Division{
    string name;        //Name of Division
    float quarter1,     //First Quarter Sales
          quarter2,     //Second Quarter Sales
          quarter3,     //Third Quarter Sales
          quarter4,     //Fourth Quarter Sales
          annualSales,  //Annual Sales
          avgQSales;    //Average Quarterly Sales
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Create fstreams for each division
    ofstream nDiv, wDiv, eDiv, sDiv;
    
    //Create Structure Variables
    Division north, west, east, south;
    
    //Set Variable Names
    north.name="North";
    west.name="West";
    east.name="East";
    south.name="South";
    
    //North Division
    cout<<"North"<<endl;
    nDiv.open("North Division Sales.txt");
    
    //Gather Sales info
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>north.quarter1;
    while(north.quarter1<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>north.quarter1;
    }
    nDiv<<north.quarter1<<endl;
    
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>north.quarter2;
    while(north.quarter2<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>north.quarter2;
    }
    nDiv<<north.quarter2<<endl;
    
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>north.quarter3;
    while(north.quarter3<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>north.quarter3;
    }
    nDiv<<north.quarter3<<endl;
    
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>north.quarter4;
    while(north.quarter4<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>north.quarter4;
    }
    nDiv<<north.quarter4<<endl;
    
    //West Division
    cout<<"West"<<endl;
    wDiv.open("West Division Sales.txt");
    
    //Gather Sales info
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>west.quarter1;
    while(west.quarter1<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>west.quarter1;
    }
    wDiv<<west.quarter1<<endl;
    
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>west.quarter2;
    while(west.quarter2<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>west.quarter2;
    }
    wDiv<<west.quarter2<<endl;
    
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>west.quarter3;
    while(west.quarter3<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>west.quarter3;
    }
    wDiv<<west.quarter3<<endl;
    
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>west.quarter4;
    while(west.quarter4<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>west.quarter4;
    }
    wDiv<<west.quarter4<<endl;
    
    //East Division
    cout<<"East"<<endl;
    eDiv.open("East Division Sales.txt");
    
    //Gather Sales info
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>east.quarter1;
    while(east.quarter1<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>east.quarter1;
    }
    eDiv<<east.quarter1<<endl;
    
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>east.quarter2;
    while(east.quarter2<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>east.quarter2;
    }
    eDiv<<east.quarter2<<endl;
    
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>east.quarter3;
    while(east.quarter3<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>east.quarter3;
    }
    eDiv<<east.quarter3<<endl;
    
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>east.quarter4;
    while(east.quarter4<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>east.quarter4;
    }
    eDiv<<east.quarter4<<endl;
    
    //South Division
    cout<<"South"<<endl;
    sDiv.open("South Division Sales.txt");
    
    //Gather Sales info
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>south.quarter1;
    while(south.quarter1<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>south.quarter1;
    }
    sDiv<<south.quarter1<<endl;
    
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>south.quarter2;
    while(south.quarter2<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>south.quarter2;
    }
    sDiv<<south.quarter2<<endl;
    
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>south.quarter3;
    while(south.quarter3<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>south.quarter3;
    }
    sDiv<<south.quarter3<<endl;
    
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>south.quarter4;
    while(south.quarter4<0){
        cout<<"Sales cannot be negative, please enter a positive value."<<endl;
        cin>>south.quarter4;
    }
    sDiv<<south.quarter4<<endl;
    
    //Close Files
    nDiv.close();
    wDiv.close();
    eDiv.close();
    sDiv.close();
    
    //Exit stage right
        return 0;
}

