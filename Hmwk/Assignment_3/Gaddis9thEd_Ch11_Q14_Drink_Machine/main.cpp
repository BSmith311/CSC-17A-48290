/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 15
* Purpose: Simulate a drink machine
*/

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Structure Declaration
struct DrinkMachine{
    string name;    //Name of Soda
    float price;    //Price of Soda
    int stock;      //Stock of Soda
};
//Function Prototypes

//Execution
int main(int argc, char** argv){
	//Declare Variables
	int pay, 
	    total=0;
	string choice;
	
	//Create Structure Variables
	DrinkMachine cola, rootbeer, lemonlime, grape, cream;
	
	//Set Structure Variable Info
	cola.name="Cola";
	cola.price=75;
	cola.stock=20;
    
	rootbeer.name="Root Beer";
	rootbeer.price=75;
	rootbeer.stock=20;
	
	lemonlime.name="Lemon-Lime";
	lemonlime.price=75;
	lemonlime.stock=20;
	
	grape.name="Grape Soda";
	grape.price=80;
	grape.stock=20;
	
	cream.name="Cream Soda";
	cream.price=80;
	cream.stock=20;
	
	//Loop Drink Machine Simulation
	do{
	    //Drink Machine Menu
	    cout<<left<<setw(11)<<cola.name;
	    cout<<cola.price<<"  "<<cola.stock<<endl;
	    
	    cout<<left<<setw(11)<<rootbeer.name;
	    cout<<rootbeer.price<<"  "<<rootbeer.stock<<endl;
	    
	    cout<<left<<setw(11)<<lemonlime.name;
	    cout<<lemonlime.price<<"  "<<lemonlime.stock<<endl;
	    
	    cout<<left<<setw(11)<<grape.name;
	    cout<<grape.price<<"  "<<grape.stock<<endl;
	    
	    cout<<left<<setw(11)<<cream.name;
	    cout<<cream.price<<"  "<<cream.stock<<endl;
	    cout<<"Quit"<<endl;
	    
	    //User Choice
	    getline(cin, choice);
	    if (choice=="Cola"){
	        //Stock Check
	        if (cola.stock==0){
	            cout<<cola.name<<" is out of stock, please select another drink."<<endl;
	            continue;
	        }
	        //Payment
	        cin>>pay;
	        cin.ignore();
	        while(pay>100 or pay<cola.price){
	            cout<<"Error, please enter enough to pay for the drink, but no more than $1.00"<<endl;
	            cin>>pay;
	            cin.ignore();
	        }
	        //Update stock, income, display change
	        total+=cola.price;
	        cola.stock-=1;
	        cout<<pay-cola.price<<endl;
	    }
	    
	    else if (choice=="Root Beer"){
	        //Stock Check
	        if (rootbeer.stock==0){
	            cout<<rootbeer.name<<" is out of stock, please select another drink."<<endl;
	            continue;
	        }
	        //Payment
	        cin>>pay;
	        cin.ignore();
	        while(pay>100 or pay<cola.price){
	            cout<<"Error, please enter enough to pay for the drink, but no more than $1.00"<<endl;
	            cin>>pay;
	            cin.ignore();
	        }
	        //Update stock, income, display change
	        total+=rootbeer.price;
	        rootbeer.stock-=1;
	        cout<<pay-rootbeer.price<<endl;
	    }
	    
	    else if (choice=="Lemon-Lime"){
	        //Stock Check
	        if (lemonlime.stock==0){
	            cout<<lemonlime.name<<" is out of stock, please select another drink."<<endl;
	            continue;
	        }
	        //Payment
	        cin>>pay;
	        cin.ignore();
	        while(pay>100 or pay<cola.price){
	            cout<<"Error, please enter enough to pay for the drink, but no more than $1.00"<<endl;
	            cin>>pay;
	            cin.ignore();
	        }
	        //Update stock, income, display change
	        total+=lemonlime.price;
	        lemonlime.stock-=1;
	        cout<<pay-lemonlime.price<<endl;
	    }
	    
	    else if (choice=="Grape Soda"){
	        //Stock Check
	        if (grape.stock==0){
	            cout<<grape.name<<" is out of stock, please select another drink."<<endl;
	            continue;
	        }
	        //Payment
	        cin>>pay;
	        cin.ignore();
	        while(pay>100 or pay<cola.price){
	            cout<<"Error, please enter enough to pay for the drink, but no more than $1.00"<<endl;
	            cin>>pay;
	            cin.ignore();
	        }
	        //Update stock, income, display change
	        total+=grape.price;
	        grape.stock-=1;
	        cout<<pay-grape.price<<endl;
	    }
	    
	    else if (choice=="Cream Soda"){
	        //Stock Check
	        if (cream.stock==0){
	            cout<<cream.name<<" is out of stock, please select another drink."<<endl;
	            continue;
	        }
	        //Payment
	        cin>>pay;
	        cin.ignore();
	        while(pay>100 or pay<cola.price){
	            cout<<"Error, please enter enough to pay for the drink, but no more than $1.00"<<endl;
	            cin>>pay;
	            cin.ignore();
	        }
	        //Update stock, income, display change
	        total+=cream.price;
	        cream.stock-=1;
	        cout<<pay-cream.price<<endl;
	    }
	    
	}while(choice!="Quit");
	
	//Output Money Made
	cout<<total<<endl;
	
	//End Program
	return 0;
}