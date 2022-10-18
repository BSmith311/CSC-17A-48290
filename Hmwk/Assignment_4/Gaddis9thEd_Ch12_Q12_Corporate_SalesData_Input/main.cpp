/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 12, 2022
 * Purpose: Corporate Sales Data Input
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Structure Declaration
struct Division{
    float quarter1,     //First Quarter Sales
          quarter2,     //Second Quarter Sales
          quarter3,     //Third Quarter Sales
          quarter4,     //Fourth Quarter Sales
          annualSales,  //Annual Sales
          avgQSales;    //Average Quarterly Sales
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float temp;
    int count;
    float annualCS=0;           //Annual Corporate Sales
    float avgQCS=0;             //Average Corporate Quarterly Sales
    float lowestQ=1000000000;   //Lowest Quarterly Sale
    float highestQ=0;           //Highest Quarterly Sale
    string lowest;              //Lowest Quarter String
    string highest;             //Highest Quarter String
    
    //Create ifstreams for each division
    ifstream nDiv, wDiv, eDiv, sDiv;
    
    //Create Structure Variables
    Division north, west, east, south, corporate;
    
    //North Division
    count=1;
    //Open the North Sales Data File
    nDiv.open("North Division Sales.txt");
    if(!nDiv){
        cout<<"Error Opening North Division Data File"<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Read the North Data File
    while(!nDiv.eof()){
        nDiv>>temp;
        if (count==1) north.quarter1=temp;
        if (count==2) north.quarter2=temp;
        if (count==3) north.quarter3=temp;
        if (count==4) north.quarter4=temp;
        count++;
    }
    
    //West Division
    count=1;
    //Open the West Sales Data File
    wDiv.open("West Division Sales.txt");
    if(!wDiv){
        cout<<"Error Opening West Division Data File"<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Read the West Data File
    while(!wDiv.eof()){
        wDiv>>temp;
        if (count==1) west.quarter1=temp;
        if (count==2) west.quarter2=temp;
        if (count==3) west.quarter3=temp;
        if (count==4) west.quarter4=temp;
        count++;
    }
    
    //East Division
    count=1;
    //Open the East Sales Data File
    eDiv.open("East Division Sales.txt");
    if(!eDiv){
        cout<<"Error Opening East Division Data File"<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Read the East Data File
    while(!eDiv.eof()){
        eDiv>>temp;
        if (count==1) east.quarter1=temp;
        if (count==2) east.quarter2=temp;
        if (count==3) east.quarter3=temp;
        if (count==4) east.quarter4=temp;
        count++;
    }
    
    //South Division
    count=1;
    //Open the South Sales Data File
    sDiv.open("South Division Sales.txt");
    if(!sDiv){
        cout<<"Error Opening South Division Data File"<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Read the South Data File
    while(!sDiv.eof()){
        sDiv>>temp;
        if (count==1) south.quarter1=temp;
        if (count==2) south.quarter2=temp;
        if (count==3) south.quarter3=temp;
        if (count==4) south.quarter4=temp;
        count++;
    }
    
    //Calculate Corporate Sales Data
    corporate.quarter1=(north.quarter1+west.quarter1
                       +east.quarter1+south.quarter1);
    corporate.quarter2=(north.quarter2+west.quarter2
                       +east.quarter2+south.quarter2);
    corporate.quarter3=(north.quarter3+west.quarter3
                       +east.quarter3+south.quarter3);
    corporate.quarter4=(north.quarter4+west.quarter4
                       +east.quarter4+south.quarter4);
    
    corporate.annualSales=(corporate.quarter1+corporate.quarter2
                          +corporate.quarter3+corporate.quarter4);
    corporate.avgQSales=(corporate.annualSales/4);
    
    //Find lowest quarter
    if (corporate.quarter1<lowestQ){
        lowestQ=corporate.quarter1;
        lowest="Quarter 1";
    }
    if (corporate.quarter2<lowestQ){
        lowestQ=corporate.quarter2;
        lowest="Quarter 2";
    }
    if (corporate.quarter3<lowestQ){
        lowestQ=corporate.quarter3;
        lowest="Quarter 3";
    }
    if (corporate.quarter4<lowestQ){
        lowestQ=corporate.quarter4;
        lowest="Quarter 4";
    }
    
    //Find highest quarter
    if (corporate.quarter1>highestQ){
        highestQ=corporate.quarter1;
        highest="Quarter 1";
    }
    if (corporate.quarter2>highestQ){
        highestQ=corporate.quarter2;
        highest="Quarter 2";
    }
    if (corporate.quarter3>highestQ){
        highestQ=corporate.quarter3;
        highest="Quarter 3";
    }
    if (corporate.quarter4>highestQ){
        highestQ=corporate.quarter4;
        highest="Quarter 4";
    }
    
    //Display Corporate Sales Data
    cout<<fixed<<setprecision(2);
    cout<<"Corporate Sales Data:"<<endl;
    cout<<"Quarter 1 Sales: $"<<corporate.quarter1<<endl;
    cout<<"Quarter 2 Sales: $"<<corporate.quarter2<<endl;
    cout<<"Quarter 3 Sales: $"<<corporate.quarter3<<endl;
    cout<<"Quarter 4 Sales: $"<<corporate.quarter4<<endl<<endl;
    cout<<"Total Annual Sales: $"<<corporate.annualSales<<endl;
    cout<<"Average Quarterly Sales: $"<<corporate.avgQSales<<endl;
    cout<<lowest<<" was the lowest quarter."<<endl;
    cout<<highest<<" was the highest quarter."<<endl;
    
    //Close Files
    nDiv.close();
    wDiv.close();
    eDiv.close();
    sDiv.close();
    
    //Exit stage right
        return 0;
}

