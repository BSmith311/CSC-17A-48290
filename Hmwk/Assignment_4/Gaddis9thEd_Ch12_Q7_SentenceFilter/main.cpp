/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 12, 2022
 * Purpose: Sentence Filter
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;

//Function prototypes
void capitalize(char *, bool &);    //Adjusts capitalization

int main()
{
   //Declare Variables
   const int SIZE=81;        //Constant for array size
   ifstream inFile;          //Input file
   ofstream outFile;         //Output file
   string inName;            //Input file name
   string outName;           //Output file name
   char inputLine[SIZE];     //Line of input
   bool midSentence = false; //Mid sentence Flag

   //Get the name of the input file and check validity
   cout<<"Enter the input file name (sentences.txt): ";
   getline(cin, inName);
   while (inName != "sentences.txt"){   //Validate input file name
       cout<<"For this program, the input file is named sentences.txt"<<endl;
       getline(cin, inName);
   }
   //Open the input file
   inFile.open(inName);
   
   //In case of error
   if (!inFile){
      cout<<"Error opening Input File: "
          <<inName<<endl;
      exit(EXIT_FAILURE);
   }
   
   //Get the output file name
   cout<<"Enter the output file name: ";
   getline(cin, outName);
   
   //Open the output file
   outFile.open(outName);
   
   //In case of error
   if (!outFile){
      cout<<"Error opening Output File: "
          <<outName<<endl;
      exit(EXIT_FAILURE);
   }
   
   // Read and process the input file.
   while (!inFile.eof()){
      char *ptr = nullptr;
      
      // Read the string from inFile.
      inFile.getline(inputLine, 81);
      
      // Capitalize the string.
      capitalize(inputLine, midSentence);
      
      //Display the line.
      cout<<inputLine<<endl;
      
      //Make ptr point to first character in inputLine
      ptr=inputLine;
 
      // Write the string to outFile
      while (*ptr != 0){
        if(*ptr=='.'){
            outFile.put(*ptr);
            outFile<<endl;
        }
        else{
            outFile.put(*ptr);
        }   
        ptr++;
      }
   }
   
   //Close the files.
   inFile.close();
   outFile.close();
   
   //End Program
   return 0;
}

//Functions
void capitalize(char *str, bool &midSentence)
{
   bool period;         //Flag

   if (midSentence)     //If true then word is lowercase
      period=false;
   else                 //Else word is lowercase and first letter is uppercase
      period=true;
      
   //Step through the string.
   while (*str != 0){
      //Skip any leading spaces
      while (*str != 0 && isspace(*str))
         str++;
      
      //If a period is encountered
      if (period && *str != 0){
         //Convert the character pointed to by str to uppercase.
         *str = toupper(*str);
         
         //Reset flag to false
         period = false;
         
         //Increment str to the next character.
         str++;
      }

      //Force the rest of the word to lowercase.
      while (*str != 0 && !isspace(*str) && *str != '.' ){
         *str = tolower(*str);
         str++;
      }
      
      //If str points to a period, set flag and increment str
      if (*str == '.'){
         period = true;
         str++;
      }
   }
   
   //Set mid sentence flag
   if (period)  //If a period is encountered, not mid sentence
      midSentence = false;
   else         //If a period is not encountered, mid sentence
      midSentence = true;
}