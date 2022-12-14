/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 13 Q5 RetailItem Class
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//User Libraries
#include "RetailItem.h"

//Execution
int main(int argc, char** argv) {
    //Define 3 instances of RetailItem Class
    RetailItem item1;
    RetailItem item2;
    RetailItem item3;
    
    //Fill item classes with mutators
    item1.setDescription("Jacket");
    item1.setUnits(12);
    item1.setPrice(59.95);
    
    item2.setDescription("Designer Jeans");
    item2.setUnits(40);
    item2.setPrice(34.95);
    
    item3.setDescription("Shirt");
    item3.setUnits(20);
    item3.setPrice(24.95);
    
    //Output results with accessors
    cout<<"Item 1: "<<item1.getDescription()<<endl;
    cout<<"Units on Hand: "<<item1.getUnits()<<endl;
    cout<<"Price: $"<<item1.getPrice()<<endl<<endl;
    
    cout<<"Item 2: "<<item2.getDescription()<<endl;
    cout<<"Units on Hand: "<<item2.getUnits()<<endl;
    cout<<"Price: $"<<item2.getPrice()<<endl<<endl;
    
    cout<<"Item 3: "<<item3.getDescription()<<endl;
    cout<<"Units on Hand: "<<item3.getUnits()<<endl;
    cout<<"Price: $"<<item3.getPrice()<<endl;
    
    //Exit
        return 0;
}