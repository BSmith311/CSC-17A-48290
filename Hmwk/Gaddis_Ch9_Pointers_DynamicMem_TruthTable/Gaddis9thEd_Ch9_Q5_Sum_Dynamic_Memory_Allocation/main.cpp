/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 18
* Purpose: Total the elemnts in a 2-D array
*/

#include <iostream>
#include <random>
using namespace std;

//Declare Functions
int **getData(int &,int &);
void prntDat(const int *const *array,int,int);
void destroy(int **array,int,int);
int sum(const int *const *array,int,int);

//Main Execution
int main(int argc, char const *argv[]){
    int **array, n, m;
    
    array=getData(n, m);
    prntDat(array, n, m);
    cout<<sum(array, n, m);
    destroy(array, n, m);
    
    //End Program
    return 0;
}

//Functions
//Return the 2-D array and its size.
int **getData(int &n, int &m){

    //Read size
    cin>>n>>m;

    //Allocate memory
    int **array=new int *[n];
    
    for (int i=0;i<n;i++){
        array[i] = new int[m];
        for (int j=0;j<m;j++)
            cin>>array[i][j];
    }
    return array;
}

//Print the 2-D Array
void prntDat(const int *const *array, int n, int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<array[i][j];
            if(j<m-1)cout<<" ";
        }
        cout<<endl;
    }
}

//Deallocate memory
void destroy(int **array, int n, int m){
    //Delete each row
    for (int i=0;i<n;i++)
        delete[] array[i];
    
    delete array;
}

//Return the Sum
int sum(const int *const *array, int n, int m){
    int Sum=0;

    //For each row
    for (int i=0;i<n;i++)
    
    //For each column
    for (int j=0;j<m;j++)
        Sum+=array[i][j];
    
    return Sum;
}