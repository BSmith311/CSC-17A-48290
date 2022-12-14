/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 28, 2022
 * Purpose: Ch 15 Q6 Essay Class
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Essay.h"

//Execution
int main(int argc, char** argv) {
    //Declare variables
    int g, s, l, c;
    
    //Get user inputs
    cout<<"Enter the points for grammar (30 points): ";
    cin>>g;
    while (g < 0 or g > 30){
        cout<<"Invalid points, range for grammar is 0-30 points: ";
        cin>>g;
    }
    
    cout<<"Enter the points for spelling (20 points): ";
    cin>>s;
    while (s < 0 or s > 20){
        cout<<"Invalid points, range for spelling is 0-20 points: ";
        cin>>s;
    }
    
    cout<<"Enter the points for correct length (20 points): ";
    cin>>l;
    while (l < 0 or l > 20){
        cout<<"Invalid points, range for length is 0-20 points: ";
        cin>>l;
    }
    
    cout<<"Enter the points for content (30 points): ";
    cin>>c;
    while (c < 0 or c > 30){
        cout<<"Invalid points, range for content is 0-30 points: ";
        cin>>c;
    }
    
    //Define instance of Essay class
    Essay student(g, s, l, c);
    
    //Set Score
    student.setScore();
    
    //Output Score
    cout<<endl<<"The student will receive "
        <<student.getScore()<<"% on the essay."<<endl;
    
    //Exit
        return 0;
}

