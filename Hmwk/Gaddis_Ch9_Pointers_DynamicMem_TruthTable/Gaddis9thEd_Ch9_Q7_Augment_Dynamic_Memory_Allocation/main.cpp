/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 18
* Purpose: Create a 2-D array 1 row and 1 column larger than 
           the array to copy with 0's in the 1st row and column 
           but filled with the other rows and columns using the original array
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

//Declare Functions
int **getData(int &,int &); //Get the Matrix Data
void printDat(const int * const *,int,int); //Print the Matrix
int **augment(const int * const *,int,int); //Augment the original array
void destroy(int **,int);   //Destroy the Matrix, i.e., reallocate memory

//Begin Main Execution
    int main() {
    //Declaring variables
    int row,col;
    int **nos;
    
    //Call Functions
    nos=getData(row,col);
    printDat(nos,row,col);
    cout<<endl;
    
    ++row;
    ++col;
    
    nos=augment(nos,row,col);
    printDat(nos,row,col);
    destroy(nos,row);
    
    //End Program
    return 0;
    }

//Functions
int **getData(int &row,int &col){   //Get the Matrix Data
    cin>>row>>col;
    
    //Create 2-D array Dynamically
    int** arr=new int*[row];
    for (int i=0;i<row;++i)
        arr[i]=new int[col];
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    return arr;

}

void printDat(const int * const *nos,int row,int col){  //Print the Matrix
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<nos[i][j];
            if(j<col-1)cout<<" ";
        }
    if(i<row-1)cout<<endl;
    }
}

int **augment(const int * const *nos,int row,int col){  //Augment the original array
    //Create 2-D array Dynamically
    int** arr=new int*[row];
    for (int i=0;i<row;++i)
    arr[i]=new int[col];
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0){
                arr[i][j]=0;
            }
            
            else if(j==0){
                arr[i][j]=0;
            }
    
            else{
                arr[i][j]=nos[i-1][j-1];
            }
        }
    }
    return arr;
}

void destroy(int **nos,int size){   //Destroy the Matrix, i.e., reallocate memory
    for (int i=0;i<size;i++){
        delete[] nos[i];
    }
}