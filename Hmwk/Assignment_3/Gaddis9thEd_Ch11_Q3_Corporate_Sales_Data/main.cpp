/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 15
 * Purpose:  Corporate Sales Data
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
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
    //Create Structure Variables
    Division north, west, east, south;
    
    //Set Variable Names
    north.name="North";
    west.name="West";
    east.name="East";
    south.name="South";
    
    //North Division
    cout<<"North"<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>north.quarter1;
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>north.quarter2;
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>north.quarter3;
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>north.quarter4;
    
    north.annualSales=(north.quarter1+north.quarter2
                      +north.quarter3+north.quarter4);
    north.avgQSales=north.annualSales/4;
    
    cout<<"Total Annual sales:$"
        <<fixed<<setprecision(2)<<north.annualSales<<endl;
    cout<<"Average Quarterly Sales:$"
        <<fixed<<setprecision(2)<<north.avgQSales<<endl;
    
    //West Division
    cout<<"West"<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>west.quarter1;
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>west.quarter2;
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>west.quarter3;
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>west.quarter4;
    
    west.annualSales=(west.quarter1+west.quarter2
                     +west.quarter3+west.quarter4);
    west.avgQSales=west.annualSales/4;
    
    cout<<"Total Annual sales:$"
        <<fixed<<setprecision(2)<<west.annualSales<<endl;
    cout<<"Average Quarterly Sales:$"
        <<fixed<<setprecision(2)<<west.avgQSales<<endl;
    
    //East Division
    cout<<"East"<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>east.quarter1;
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>east.quarter2;
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>east.quarter3;
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>east.quarter4;
    
    east.annualSales=(east.quarter1+east.quarter2
                     +east.quarter3+east.quarter4);
    east.avgQSales=east.annualSales/4;
    
    cout<<"Total Annual sales:$"
        <<fixed<<setprecision(2)<<east.annualSales<<endl;
    cout<<"Average Quarterly Sales:$"
        <<fixed<<setprecision(2)<<east.avgQSales<<endl;
    
    //South Division
    cout<<"South"<<endl;
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>south.quarter1;
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>south.quarter2;
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>south.quarter3;
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>south.quarter4;
    
    south.annualSales=(south.quarter1+south.quarter2
                      +south.quarter3+south.quarter4);
    south.avgQSales=south.annualSales/4;
    
    cout<<"Total Annual sales:$"
        <<fixed<<setprecision(2)<<south.annualSales<<endl;
    cout<<"Average Quarterly Sales:$"
        <<fixed<<setprecision(2)<<south.avgQSales;
    
    //Exit stage right!
    return 0;
}
