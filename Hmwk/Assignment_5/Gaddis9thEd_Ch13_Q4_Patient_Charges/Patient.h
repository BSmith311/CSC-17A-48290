/* 
 * File:   Patient.h
 * Author: Brandon Smith
 *
 * Created on November 21, 2022
 */

#ifndef PATIENT_H
#define PATIENT_H

class Patient{
    private:
        string name;
        string address;
        string phone;
        string emergContact;
        
    public:
        //Constructor
        Patient()
        {name = "";
        address = "";
        phone = "";
        emergContact = "";}
        
        //Mutators
        void setName(string n)
        {name = n;}
        void setAddress(string a)
        {address = a;}
        void setPhone(string p)
        {phone = p;}
        void setEmerg(string e)
        {emergContact = e;}
        
        //Accessors
        string getName() const
        {return name;}
        string getAddress() const
        {return address;}
        string getPhone() const
        {return phone;}
        string getEmerg() const
        {return emergContact;}
};

#endif /* PATIENT_H */

