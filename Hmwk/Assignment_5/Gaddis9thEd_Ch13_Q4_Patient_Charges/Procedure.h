/* 
 * File:   Procedure.h
 * Author: Brandon
 *
 * Created on November 21, 2022
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H

class Procedure{
    private:
        string name;
        string date;
        string docName;
        float charges;
        
    public:
        //Constructor
        Procedure(string n, string d, string dn, float c)
        {
            name = n;
            date = d;
            docName = dn;
            charges = c;
        }
        
        //Mutators
        //I know the book asked to use mutators, but since pre-existing info
        //was supposed to be used I utilized the constructor instead
        
        //Accessors
        string getName() const
        {return name;}
        string getDate() const
        {return date;}
        string getDocName() const
        {return docName;}
        float getCharges() const
        {return charges;}
};

#endif /* PROCEDURE_H */

