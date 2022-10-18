/*
* File   main.cpp
* Author Brandon Smith
* Created on September 18
* Purpose: Augment a 1-D array by 1 element
*/

#include <iostream>
using namespace std;

//Declare Functions
int *getData(int &);
int *augment(const int *arr,int);
void prntAry(const int *arr,int);

//Main execution
int main() {
    int n;
    cin>>n;
    int *arr = getData(n);
    
    //Print Arrays
    prntAry(arr, n);
    cout<<endl;
    
    arr=augment(arr, n);
    prntAry(arr, n+1);
    
    //End program
    return 0;
}

//Functions
//Read the array
int *getData(int &n){
    int *arr = new int[n];
    
    for (int i=0;i<n;i++){  //Loop to read array
        cin>>arr[i];
    }
    
    return arr;
}

//Augment and copy the original entry
int *augment(const int *arr, int n){
    int *res = new int[n + 1];
    res[0]=0;
    
    for (int i=0;i<n;i++){
        res[i+1]=arr[i];
    }
    return res;
}

//Print the Array
void prntAry(const int *arr, int n) {
    for (int i=0;i<n;i++){
        cout<<arr[i];
        if(i<n-1)cout<<" ";
    }
}