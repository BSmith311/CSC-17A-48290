/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 15
* Purpose: Read and Display Movie Data using Structures
*/

//System Libraries
#include <iostream>
using namespace std;

//Structure Declaration
struct MovieData{
    string title,    //Movie Title
           director; //Movie Director
    int year,        //Year of Release
        runtime;     //Runtime in minutes
};

//Execution
int main(int argc, char** argv){
	//Declare Variables
	int numM;        //Number of movies
	
	//Initial Outputs
	cout<<"This program reviews structures"<<endl;
	cout<<"Input how many movies, the Title of the Movie, "
	    <<"Director, Year Released, and the Running Time in (minutes)."<<endl<<endl;
	cin>>numM;       //Number of Movies
	cin.ignore();
	
	//Structure Variables
	MovieData movie[numM];
	for(int i=0; i<numM;i++){
	    getline(cin, movie[i].title);       //Read Movie Title
	    getline(cin, movie[i].director);    //Read Movie Director
	    cin>>movie[i].year;                 //Read Movie Year
	    cin.ignore();
	    cin>>movie[i].runtime;              //Read Movie Runtime
	    cin.ignore();
	}
	
	//Movie Data Output
	for(int i=0; i<numM;i++){
	    cout<<"Title:     "<<movie[i].title<<endl;      //Display Movie Title
	    cout<<"Director:  "<<movie[i].director<<endl;   //Display Movie Director
	    cout<<"Year:      "<<movie[i].year<<endl;       //Display Movie Year
	    cout<<"Length:    "<<movie[i].runtime<<endl;    //Display Movie Runtime
	    if (i+1<numM)cout<<endl;
	}
	    
	//End Program
	return 0;
}