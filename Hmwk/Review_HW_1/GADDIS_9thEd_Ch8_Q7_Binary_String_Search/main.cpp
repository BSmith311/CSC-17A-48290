/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 8, 2022
 * Purpose: Binary Search String
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Mathematical/Physics/Conversions, Higher dimensioned arrays

//Function Prototypes
void sort(string[],int);
void display(string[],int);
int binSearch(string[],int,string);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const int NAMES=20;
    string search;
    string names[NAMES]={"Collins, Bill", "Smith, Bart", "Allen, Jim",
                         "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                         "Taylor, Terri", "Johnson, Jill",
                         "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                         "James, Jean", "Weaver, Jim", "Pore, Bob",
                         "Rutherford, Greg", "Javens, Renee",
                         "Harrison, Rose", "Setzer, Cathy",
                         "Pike, Gordon", "Holland, Beth"};
    //Sort the Array
    sort(names,NAMES);                     //Calls sort function
    //Display sorted array
    cout<<"Here is the sorted list of names:"<<endl;
    cout<<"---------------------------------"<<endl;
    display(names,NAMES);
    //User inputs name
    cout<<"Enter the name you want to search for:"<<endl;
    getline(cin,search);
    //Search for name
    int results=binSearch(names,NAMES,search);
    if (results==-1){
        cout<<"That name is not in the array."<<endl;
    }
    else{
        cout<<"The name is found at element "<<results
            <<" in the array."<<endl;
    }
    //Exit stage right
        return 0;
}

void sort(string values[],int size){       //Performs a Selection Sort
    int startScan;
    int minI;
    string minV;
    
    for (startScan=0;startScan<(size-1);startScan++){
        minI=startScan;
        minV=values[minI];
        
        for (int index=startScan+1; index<size;index++){
            if (values[index]<minV){
                minV=values[index];
                minI=index;
            }
        }
        values[minI]=values[startScan];
        values[startScan]=minV;
    }
}

void display(string values[],int size){
    for (int i=0;i<size;i++){
        cout<<values[i]<<endl;
    }
}

int binSearch(string values[],int size,string value){
    bool found=false;       //Flag
    int first=0;            //First array element holder
    int middle;             //Mid point holder
    int last=size-1;        //Last array element holder
    int position=-1;        //Search value position holder
    
    while(!found && first<=last){
        middle=(first+last)/2;          //Calculate mid point
        if (values[middle]==value){     //Check midpoint for value
            position=middle;
            found=true;
        }
        else if (values[middle]>value){ //Check lower half for value
            last=middle-1;
        }
        else first=middle+1;            //Upper half has value
    }
    return position;        //Returns position
}