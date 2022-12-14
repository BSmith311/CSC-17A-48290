/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 22, 2022
 * Purpose: Ch 13 Q6 Inventory Class
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Inventory.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    int n, q;
    float c, t;
    
    //Get user inputs
    cout<<"Enter the item number: ";
    cin>>n;
    while (n < 0){
        cout<<"Invalid item number, cannot be negative. Enter the item number: ";
        cin>>n;
    }
    
    cout<<"Enter the item quantity: ";
    cin>>q;
    while (q < 0){
        cout<<"Invalid item quantity, cannot be negative. Enter the item quantity: ";
        cin>>q;
    }
    
    cout<<"Enter the item cost: ";
    cin>>c;
    while (c < 0){
        cout<<"Invalid item cost, cannot be negative. Enter the item cost: ";
        cin>>c;
    }
    
    t = (c * q);
    
    //Define instance of Inventory class and fill with constructor
    Inventory item(n,q,c,t);
    
    //Output results using Accessors
    cout<<endl<<"Item Number: "<<item.getItemNumber()<<endl;
    cout<<"Item Quantity: "<<item.getQuantity()<<endl;
    cout<<"Item Cost: $"<<fixed<<setprecision(2)<<item.getCost()<<endl;
    cout<<"Total Cost: $"<<item.getTotalCost()<<endl;
    
    //Exit
        return 0;
}

