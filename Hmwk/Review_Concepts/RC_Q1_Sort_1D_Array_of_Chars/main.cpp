/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 5
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    //Exit
    return 0;
}

//Functions
int read(char *arr)                 //Function to read input
{
    string s;                       //String input
    cin>>s;                         //User input
    strcpy(arr, s.c_str());         //Convert string to char array and copy
    return s.length();              //Return string length
}

void sort(char *arr, int n)         //Sort function
{
    int i, key, j;                  //Counters place holders
    for (i=1; i<n; i++)             //Sort loop
    {
        key=arr[i];                 //Temporary placeholder
        j=i-1;                      
        while (j>=0 && arr[j]>key)  //Moves values to correct place
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void print(const char arr[],int n)  //Print function
{
    for(int i=0; i<n; i++)          //Output loop
    {
        cout<< arr[i] << "";
    }
    cout<<endl;                     //Formatting
}