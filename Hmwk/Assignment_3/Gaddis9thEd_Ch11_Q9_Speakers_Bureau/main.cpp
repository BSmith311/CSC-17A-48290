/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 27, 2022
 * Purpose: Speaker's Bureau
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Structure Declaration
struct SpeakerBureau{
    string name,
           telenum,
           topic;
    float  feeReq;
};

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    char choice;
    SpeakerBureau speaker[SIZE];
    int arrSize=0;
    int edit;
    
    //Program Loop
    while(choice!='4'){
        //Output Menu
        cout<<"-----------------------------------------"<<endl;
        cout<<"Please select from the following choices:"<<endl;
        cout<<"1. Add a new speaker."<<endl;
        cout<<"2. Edit a speaker's details."<<endl;
        cout<<"3. Display the list of current speakers."<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"-----------------------------------------"<<endl;
        //User Choice
        cin>>choice;
        cin.ignore();
        switch(choice){
            case '1':
                //Read the new speaker's name
                arrSize++;
                cout<<"Please enter the name of the new Speaker"<<endl;
                getline(cin, speaker[arrSize].name);
                
                //Set Default information
                speaker[arrSize].telenum="No Telephone Number Provided";
                speaker[arrSize].topic="No Topic Provided";
                speaker[arrSize].feeReq=0;
                break;
            
            case '2':
                //Invalid choice if there are no speakers
                if(arrSize==0){
                    cout<<"Invalid choice, no speakers available to edit"<<endl;
                    break;
                }
                
                //Ask for which speaker to edit
                cout<<"Which Speaker's details would you like to edit?"<<endl;
                for (int i=1;i<=arrSize;i++){
                    cout<<"Speaker "<<i<<": "<<speaker[i].name<<endl;
                }
                cin>>edit;
                cin.ignore();
                //Validate Input
                while (edit>arrSize or edit<=0){
                    cout<<"Invalid choice, please enter a valid number."<<endl;
                    cin>>edit;
                    cin.ignore();
                }
                
                //Edit the selected speaker
                cout<<"Now Editing details for "<<speaker[edit].name<<endl;
                cout<<"Enter the speaker's telephone number:"<<endl;
                getline(cin, speaker[edit].telenum);
                cout<<"Enter the speaker's topic:"<<endl;
                getline(cin, speaker[edit].topic);
                cout<<"Enter the speaker's required fee in dollars:"<<endl;
                cin>>speaker[edit].feeReq;
                cin.ignore();
                while (speaker[edit].feeReq<0){
                    cout<<"Required Fee cannot be negative."<<endl;
                    cin>>speaker[edit].feeReq;
                    cin.ignore();
                }
                break;
            
            case '3':
                char buffer;
                cout<<"-----------------------------------------"<<endl;
                cout<<"Here is the list of current speakers:"<<endl;
                
                //List Speaker Names
                for (int i=1;i<=arrSize;i++){
                    cout<<"Name:             "<<speaker[i].name<<endl;
                    cout<<"Telephone Number: "<<speaker[i].telenum<<endl;
                    cout<<"Speaking Topic:   "<<speaker[i].topic<<endl;
                    cout<<"Fee Required:     $"<<speaker[i].feeReq<<endl;
                    cout<<endl;
                }
                cout<<"-----------------------------------------"<<endl;
                //Buffer before menu output
                cout<<endl<<"Enter any input to continue."<<endl;
                cin>>buffer;
                cin.ignore();
                break;
            
            case '4':
                break;
            
            default:
                cout<<"Invalid choice, please enter a number between 1-4."<<endl;
                break;
        }
    }
    
    //Exit stage right
        return 0;
}