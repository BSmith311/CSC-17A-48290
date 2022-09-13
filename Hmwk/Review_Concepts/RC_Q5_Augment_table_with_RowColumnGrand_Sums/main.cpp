/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 5
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);                  //Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);   //Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);           //Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

//Functions
void read(int array[][COLMAX], int &row, int &col)
{
    cout<<"Input a table and output the Augment row,col and total sums."<<endl;     //Input prompt
    cout<<"First input the number of rows and cols. <20 for each"<<endl;            //Rows and columns prompt
    cin>>row>>col;                                                                  //Inputs
    cout<<"Now input the table."<<endl;                                             //Table prompt
    
    for (int i=0; i<row; i++)           //Table values inputs loop
    {
        for (int j=0; j<col; j++)
        {
            cin>>array[i][j];
        }
    }
}

void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX])
{
    int rowSum;             //Row Sum
    int colSum;             //Column Sum
    int grandTotal=0;       //Grand Sum
    
    for (int i=0; i<row; i++)           //Column array augment
    {
        rowSum=0;                       //Set default row sum value
        for (int j=0; j<col; j++)       //Calculate sum of row and column augment
        {
            rowSum+=array[i][j];
            augAry[i][j]=array[i][j];
        }
        augAry[i][col]=rowSum;          //Row sum augment
        grandTotal+=rowSum;             //Adds row sum to grand total
    }
    for (int i = 0; i < col; i++)       //Row array augment
    {
        colSum = 0;                     //Sets default column sum value
        for (int j = 0; j < row; j++)   //Calculate sum of column
        {
            colSum += array[j][i];
        }
        augAry[row][i] = colSum;        //Column sum augment
    }
    augAry[row][col] = grandTotal;      //Adds to grand total
}

void print(const int array[][COLMAX], int row, int col, int width)
{
    for (int i = 0; i < row; i++)               //Rows and columns loops
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(width) << array[i][j]; //Prints array value
        }
        cout << endl;                           //Formatting
    }
}