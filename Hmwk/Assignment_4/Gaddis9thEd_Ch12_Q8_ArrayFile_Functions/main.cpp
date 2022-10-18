/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 11, 2022
 * Purpose: Array/File Functions
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Function Prototypes
void arrayToFile(string,int*,int);     //Write the contents of the array in binary mode
void fileToArray(string,int*,int);     //Read  the contents of the array in binary mode

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string fileName;            //Strings for the file name
    int arrSize=10;             //Size of array
    int array[arrSize]={1,2,3,4,5,
                        6,7,8,9,10};
    
    //Get the name of the files
    cout<<"Enter the name of the file."<<endl;
    cin>>fileName;
    
    //Call functions
    arrayToFile(fileName,array,arrSize);
    fileToArray(fileName,array,arrSize);
    
    //Output the array
    cout<<"The array read from the file is:"<<endl;
    for (int i=0; i<arrSize; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    //Exit stage right
        return 0;
}

//Functions
void arrayToFile(string fileName,int *arr,int size){
    fstream file;          //Fstream for the file output
    cout<<"Opening the file in output and binary mode."<<endl;
    file.open(fileName,ios::out | ios::binary);  //Open input file
    
    //Write the array into the file
    cout<<"Writing the array to the file."<<endl;
    file.write(reinterpret_cast<char *>(&arr), size);
    
    //Close the File
    cout<<"Closing the file."<<endl<<endl;
    file.close();
}

void fileToArray(string fileName,int *arr,int size){
    fstream file;           //Fstream for the file input
    cout<<"Opening the file in input and binary mode."<<endl;
    file.open(fileName,ios::in | ios::binary);     //Open output file
    
    //Read into the array
    cout<<"Reading the file to the array."<<endl;
    file.read(reinterpret_cast<char *>(&arr), size);
    
    //Close the File
    cout<<"Closing the file."<<endl<<endl;
    file.close();
}