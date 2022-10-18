/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 13, 2022
 * Purpose: String Search
 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Function Prototype
int search(ifstream&, string);  //Search the file for the string

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string fileName,    //File name
           uString;     //String to search for
    ifstream inFile;    //Input File
    
    //Get the file name
    cout<<"Please enter the name of the file (strings.txt): ";
    cin>>fileName;
    while (fileName != "strings.txt"){   //Validate input file name
       cout<<"For this program, the input file is named strings.txt"<<endl;
       cin>>fileName;
    }
    
    //Open the file
    inFile.open(fileName);
    
    //In case of error
    if (!inFile){
      cout<<"Error opening Input File: "
          <<fileName<<endl;
      exit(EXIT_FAILURE);
    }
    
    //Get string to search for
    cout<<"Please enter the string you want to search for (case sensitive): ";
    cin>>uString;
    cout<<endl;
    
    //Search the file and output results
    cout<<"The string '"<<uString<<"' is found in the following lines:"<<endl;
    int found = search(inFile, uString);
    cout<<endl<<"The string '"<<uString<<"' was found in "<<found<<" lines."<<endl;
    
    //Close the file
    inFile.close();
    
    //Exit stage right
        return 0;
}

//Functions
int search(ifstream &inFile,string uString){
    string line;                                //Current line
    if(getline(inFile, line)) {                 //If there is a line to search
        if(line.find(uString) != -1) {          //If the string is in the line
            cout<<line<<endl;                   //Output current line
            return 1+search(inFile, uString);   //Return 1 and rerun function
        } else {                                //Else string is not in the line
            return search(inFile, uString);     //Rerun function
        }
    } else {                                    //No more lines in file
        return 0;                               //Return 0 (do not rerun function)
    }
}