/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on Sept 1
 * Purpose: Create a parallel array that represents
 *          the succesive sum of preceding members in the array
 */

#include <iostream>
using namespace std;

//Return the array size and the array from the inputs
int *getData(int &);

//Return the array with successive sums
int *sumAry(const int *,int);

//Print the array
void prntAry(const int *,int);

//Begin Execution
int main(int argc,char const *argv[]){
    int n;

    //Read data
    int *array=getData(n);

    //Perform sum
    int *sum=sumAry(array, n);

    //Print data
    prntAry(array,n);
    cout<<endl; 
    prntAry(sum,n);

    return 0;
}

//Functions
//Return the array size and the array from the inputs
int *getData(int &n){
    //Read size
    cin>>n;
    
    //Allocate memory
    int *array=new int[n];
    
    //Read array
    for (int i=0;i<n;i++)
        cin>>array[i];
    
    return array;
}

//Return the array with successive sums
int *sumAry(const int *array,int n){
    int *sum=new int[n];
    
    sum[0]=array[0];
    
    for (int i=1;i<n;i++)
        sum[i]=sum[i-1]+array[i];
    
    return sum;
}

//Print the array
void prntAry(const int *array,int n){
    for (int i=0;i<n;i++){
      cout<<array[i];
      if(i!=n-1)cout<<" ";
    }
}