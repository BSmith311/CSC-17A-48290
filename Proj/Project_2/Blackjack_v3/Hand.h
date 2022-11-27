/* 
 * File:   Hand.h
 * Author: Brandon
 *
 * Created on November 27, 2022
 */

#ifndef HAND_H
#define HAND_H

class Hand{
    private:
        static const int size = 22;
        string *cardN;
        int *cardP;
        int cardTotal;
        
    public:
        //Constructor
        Hand()
        {
            cardN = new string[size];
            cardP = new int[size];
            for (int i = 0; i < size; i++)
            {
                cardN[i] = "";
                cardP[i] = 0;
            }
            cardTotal = 0;
        }
        
        //Destructor
        ~Hand()
        {
            delete [] cardN;
            delete [] cardP;
            cardTotal = 0;
        }
        
        //Mutators
        void setHand(const int,ifstream&,string);
        void addTotal(int);
        
        
        //Accessors
        void printHand();
        int getTotal() const
        {return cardTotal;}
};

#endif /* HAND_H */

