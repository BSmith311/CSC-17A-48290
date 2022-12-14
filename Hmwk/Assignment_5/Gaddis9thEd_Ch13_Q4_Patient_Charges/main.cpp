/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 21, 2022
 * Purpose: Ch 13 Q4 Patient Charges
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Patient.h"
#include "Procedure.h"

//Execution
int main(int argc, char** argv) {
    //Declare Variables
    string n, a, p, e;
    
    //Define instance of Patient Class
    Patient patient;
    
    //Get user inputs
    cout<<"Enter the Patient's full name: ";
    getline(cin, n);
    
    cout<<"Enter the Patient's address, city, state, and ZIP code: ";
    getline(cin, a);
    
    cout<<"Enter the Patient's phone number: ";
    getline(cin, p);
    
    cout<<"Enter the Patient's emergency contact name and number: ";
    getline(cin, e);
    
    //Call Patient Class Mutators
    patient.setName(n);
    patient.setAddress(a);
    patient.setPhone(p);
    patient.setEmerg(e);
    
    //Define 3 instances of Procedure Class, fill with given info
    Procedure procedure1("Physical Exam","11/21/2022","Dr. Irvine",250.00);
    Procedure procedure2("X-ray","11/21/2022","Dr. Jamison",500.00);
    Procedure procedure3("Blood Test","11/21/2022","Dr. Smith",200.00);
    
    //Output Results using Accessors
    //Patient Class  
    cout<<endl<<"Patient Info:"<<endl;
    cout<<"Name: "<<patient.getName()<<endl;
    cout<<"Address: "<<patient.getAddress()<<endl;
    cout<<"Phone Number: "<<patient.getPhone()<<endl;
    cout<<"Emergency Contact Name and Number: "<<patient.getEmerg()<<endl;
    
    //Procedure Class
    cout<<endl<<"Procedure 1 Info: "<<endl;
    cout<<"Procedure Name: "<<procedure1.getName()<<endl;
    cout<<"Date: "<<procedure1.getDate()<<endl;
    cout<<"Practitioner: "<<procedure1.getDocName()<<endl;
    cout<<"Charge: $"<<fixed<<setprecision(2)<<procedure1.getCharges()<<endl;
    
    cout<<endl<<"Procedure 2 Info: "<<endl;
    cout<<"Procedure Name: "<<procedure2.getName()<<endl;
    cout<<"Date: "<<procedure2.getDate()<<endl;
    cout<<"Practitioner: "<<procedure2.getDocName()<<endl;
    cout<<"Charge: $"<<fixed<<setprecision(2)<<procedure2.getCharges()<<endl;
    
    cout<<endl<<"Procedure 3 Info: "<<endl;
    cout<<"Procedure Name: "<<procedure3.getName()<<endl;
    cout<<"Date: "<<procedure3.getDate()<<endl;
    cout<<"Practitioner: "<<procedure3.getDocName()<<endl;
    cout<<"Charge: $"<<fixed<<setprecision(2)<<procedure3.getCharges()<<endl;
    
    //Exit
        return 0;
}