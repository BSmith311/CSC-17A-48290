/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 5
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

//Functions
void read(vector<int>& ev,vector<int>& od)
{
    int size, number;       //Size, number
    cout<<"Input the number of integers to input."<<endl;   //Input prompt
    cin>>size;              //Input
    
    cout<<"Input each number."<<endl;                       //Input prompt
    for (int i=0; i<size; i++)                              //Input loop
    {
        cin>>number;      //Input
        
        if (number%2 == 0) ev.push_back(number);    //If even
        else od.push_back(number);                  //If odd
    }
}

void copy(vector<int> ev,vector<int> od,int arr[][COLMAX])
{
    int eSize=ev.size();        //Sets even size
    int oSize=od.size();        //Sets odd size
    int i=0, j=0;               //Counters
    
    while (i<=eSize)            //Even copy loop
    {
        arr[i][0]=ev[i];
        i++;                    //Increments counter
    }
    while (j<=eSize)           //Odd copy loop
    {
        arr[j][1]=od[j];  
        j++;                    //Increments counter
    }
    
}

void prntVec(vector<int> ev,vector<int> od,int size)
{
    cout<<setw(size)<<"Vector"          //Vector print output
        <<setw(size)<<"Even"
        <<setw(size)<<"Odd"<<endl;
    
    int i=0;                            //Counter
    while(i<ev.size() && i<od.size())   //Loop for vector output
    {
        cout<<setw(size*2)<<ev[i];      //Outputs even
        cout<<setw(size)<<od[i]<<endl;  //Outputs odd
        i++;                            //Increments counter
    }
    while (i<ev.size())                //Loop for leftover even output
    {
        cout<<setw(size*2)<<ev[i];      //Outputs even
        i++;                            //Increments counter
        cout<<setw(size)<<" "<<endl;    //Formatting
    }
    
    while (i<od.size())                 //Loop for leftover odd output
    {
        cout<<setw(size*3)<<od[i]<<endl;//Outputs odd
        i++;                            //Increments counter
    }
}

void prntAry(const int arr[][COLMAX],int eSize,int oSize,int size)
{
      cout<<setw(size)<<"Array"         //Array output
          <<setw(size)<<"Even"
          <<setw(size)<<"Odd"<<endl;
    
    int i=0, j=0;                       //Counters
    while(i<eSize && j<oSize)           //Loop for array output
    {
        cout<<setw(size*2)<<arr[i][0];    //Outputs even
        cout<<setw(size)<<arr[j][1]<<endl;//Outputs odd
        i++;                              //Increments counter
        j++;                              //Increments counter
    }
    
    while (i<eSize)                     //Loop for leftover even
    {
        cout<<setw(size*2)<<arr[i][0];  //Outputs even
        i++;                            //Increments counter
        cout<<setw(size)<<" "<<endl;    //Formatting
    }
    while (j<oSize)
    {
        cout<<setw(size*3)<<arr[j][1]<<endl;  //Outputs odd
        j++;                                  //Increments counter
    }
}