/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 18
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

int *getData(int &); //Fill the array
int *sort(const int *,int); //Sort smallest to largest
int *reverse(const int *,int); //Sort in reverse order
void prntDat(const int *,int); //Print the array

//Begin Execution
int main() {
    //Declare Variables
    int* nos;
    int size;
    
    //Initialize Variables
    nos=getData(size);
    nos=sort(nos,size);
    
    prntDat(nos,size);
    cout<<endl;
    nos=reverse(nos,size);
    prntDat(nos,size);
    
    //End Program
    return 0;
    }


//Functions
int *getData(int &size){
    cin>>size;
    
    //Create array dynamically
    int* nos=new int[size];
    for(int i=0;i<size;i++){
        cin>>nos[i];
    }
    
    return nos;
}

int *sort(const int *nos,int size){     //Sort smallest to largest
    // Create array dynamically
    int* array = new int[size];
    for(int i=0;i<size;i++){
        array[i]=nos[i];
    }
    
    //Sort array in ascending order
    int temp;
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    return array;
}

int *reverse(const int *nos,int size){      //Sort in reverse order
    // Creating array dynamically
    int* array = new int[size];
    for(int i=0;i<size;i++){
        array[i]=nos[i];
    }
    
    //Sort the array ascending order
    int temp;
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (array[i]<array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    return array;
}

void prntDat(const int *nos,int size){      //Print the Array
    for(int i=0;i<size;i++){
        cout<<nos[i];
        if(i<size-1)cout<<" ";
    }
}