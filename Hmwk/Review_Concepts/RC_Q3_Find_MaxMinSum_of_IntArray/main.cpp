/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 5
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min
    
    //Exit
    return 0;
}

//Functions
void read(int array[],int n)                //Reads and outputs input
{
    for(int i=0; i<n; i++)                  //Input output loop
    {
        cout<<"a["<<i<<"]"<<" = ";          //Outputs input prompt
        cin>>array[i];                      //Input
        cout<<array[i]<<endl;               //Outputs input
    }
}

int stat(const int array[],int n,int& max,int& min)     //Calculates sum, min, max
{
    min=1000000;                        //Default min value
    max=-1000000;                       //Default max value
    int sum=0;                          //Default sum value
    for (int i=0; i<n; i++)             //Loop to set values
    {
        sum+=array[i];                  //Adds array to sum
        if(max<array[i])                //If max is less than array
        {
            max=array[i];               //Sets new max value
        }
        if (min>array[i])               //If min is more than array
        {
            min=array[i];               //Sets new min value
        }
    }
    return sum;                         //Returns sum value
}

void print(const int array[],int n,int sum,int max,int min)     //Prints final output
{
    cout<<"Min  = "<<min<<endl;             //Min output
    cout<<"Max  = "<<max<<endl;             //Max output
    cout<<"Sum  = "<<sum<<endl;             //Sum output
}