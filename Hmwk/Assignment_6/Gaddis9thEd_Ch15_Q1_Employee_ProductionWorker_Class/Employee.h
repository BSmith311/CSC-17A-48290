/* 
 * File:   Employee.h
 * Author: Brandon
 *
 * Created on November 27, 2022
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
    private:
        string name;
        string number;
        string date;
        
    public:
        //Constructors
        Employee()
        {name =   "";
         number = "";
         date =   "";}
        
        Employee(string n, string num, string d)
        {name   = n;
         number = num;
         date   = d;}
        
        
        //Mutators
        void setName(string n)
        {name   = n;}
        void setNumber(string num)
        {number = num;}
        void setDate(string d)
        {date   = d;}
        
        //Accessors
        string getName() const
        {return name;}
        string getNumber() const
        {return number;}
        string getDate() const
        {return date;}
        
        
};

#endif /* EMPLOYEE_H */

