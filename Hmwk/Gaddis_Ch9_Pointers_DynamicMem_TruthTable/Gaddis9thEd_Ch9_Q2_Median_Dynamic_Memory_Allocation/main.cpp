/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 19
* Purpose: Calculate the Median of a dynamic float array and print the results
*/

#include <iostream>
#include <iomanip>
using namespace std;

int *getData(int &);
void prntDat(int *,int);
float *median (int* numbers, int size);
void prntMed(float *,int);

//Begin Execution
int main(){
    int actualSize=0;
    int *numbers=getData(actualSize);

    //Print the integer array    
    prntDat(numbers, actualSize);
    cout<<endl;
    
    //Fill and print the median array
    float * m=median(numbers, actualSize);
    prntMed(m, actualSize);
    
    //End Program
    return 0;
}

//Functions
int* getData(int& size){        //Return the array size and the array
    int n;
    cin>>n;
    int *num = new int[n];
    
    for(int i=0;i<n;++i)
        cin>>num[i];
    
    size=n;
    return num;
}

void prntDat (int *arr,int n){  //Print the integer array
    for(int i=0; i<n;++i){
        cout<<fixed<<arr[i];
        if (i<n-1)cout<<" ";
    }
}

//Fill the median array with the float array size, the median, and the integer array data
float *median(int* numbers,int size){  
    float *arr=new float[size+2];
    
    int sortnum[size];
    for (int i=0;i<size;i++){   //Copy the array to a new array to sort
        sortnum[i]=numbers[i];
    }
    
    //Sort the Array
    for (int max=size-1;max>0;max--){
        for (int i=0;i<max;i++){
            if (sortnum[i]>sortnum[i+1]){
                swap(sortnum[i], sortnum[i+1]);
            }
        }
    }
    
    //Find the Median
    for(int i=2;i<size+2;++i)
        arr[i]=1.0*numbers[i-2];
    arr[0]=size+2;
    
    //Odd Number
    if(size%2 != 0){
        float median=(sortnum[size/2]);
        arr[1]=median;
    }
    
    //Even Number
    else{
        int index1=(size/2)-1;
        int index2=size/2;
        
        float median=((sortnum[index1]+sortnum[index2])/2.0);
        arr[1]=median;
    }
    return arr;
}

void prntMed (float *arr,int n){  //Print the median Array
    cout<<fixed<<setprecision(0)<<arr[0]<<" ";
    for(int i=1; i<n+2;++i){
        cout<<fixed<<setprecision(2)<<arr[i];
        if(i<n+1)cout<<" ";
    }
}