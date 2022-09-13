/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 5
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int read(char array[][COLMAX],int *rowDet);         //Outputs row and columns detected from input
void sort(char array[][COLMAX],int rows,int cols);  //Sort by row
void print(char array[][COLMAX],int rows,int cols); //Print the sorted 2-D array
//Program Execution Begins Here
int main(int argc, char** argv)
{
    //Declare all Variables Here
    const int ROW=30;               //Only 20 required
    char array[ROW][COLMAX];        //Bigger than necessary
    int colIn,colDet,rowIn,rowDet;  //Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,&rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(colDet<=colIn)
    {
        colDet=colIn;
    }
    
    if(rowDet==rowIn&&colDet==colIn)
        {
            sort(array,rowIn,colIn);
            cout<<"The Sorted Array"<<endl;
            print(array,rowIn, colIn);
        }
    else
    {
        if(rowDet!=rowIn)
        {
            cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        }
        if(colDet!=colIn)
        {
            cout<<(colDet<colIn?"Column Input size less than specified.":
        "Column Input size greater than specified.")<<endl;
        }
    }

    //Exit
    return 0;
}

//Functions
int read(char array[][COLMAX],int *rowDet)
{
    int i;                                      //Counter
    int rows=0;                                 //Default value for rows
    int cols=0;                                 //Default value for columns
    string input;                               //Input
    int len;                                    //Length of input
    for(i=0; i<*rowDet; i++)                    //Array loop
    {
        cin>>input;
        len=input.length();
        if(len>0 && len<COLMAX)                 //If statement to enter value into array
        {
            strcpy(array[rows],input.c_str());  //Copies string to array
            rows++;                             //Row increment
            if(len>cols)
            {
                cols=len;
            }
        }
        else
        {
            cout<<"Error Occured: Input String length should be > 0 and < "<<COLMAX<<endl;
        }
    }
    *rowDet=rows;
    return cols;
}

void sort(char array[][COLMAX],int rows,int cols)
{
    int i,j;                                            //Counters
    char temp[COLMAX];                                  //Temporary placeholder
    for(i=0; i<rows; i++)                               //Sorting loop
    {
        for(j=0; j<rows-1; j++)                         //Sorting loop
            {
                if(strcmp(array[j],array[j+1]) > 0)
                    {
                        strcpy(temp,array[j]);
                        strcpy(array[j],array[j+1]);
                        strcpy(array[j+1],temp);
                    }
            }
        }
}

void print(char array[][COLMAX],int rows,int cols)
{
    int i;                      //Counter
    for(i=0;i<rows;i++)         //Output loop
    {
        printf("%s",array[i]);
        cout<<endl;             //Formatting
    }
}