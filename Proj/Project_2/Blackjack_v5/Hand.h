/* 
 * File:   Hand.h
 * Author: Brandon
 *
 * Created on November 30, 2022
 */

#ifndef HAND_H
#define HAND_H
#include <iomanip>

class Hand
{
    private:
        static const int size = 22;
        string *cardName;
        int *cardPoint;
        int cardsDrawn;
        int handTotal;
        
    public:
        //Constructor
        Hand()
        {
            cardName = new string[size];
            cardPoint = new int[size];
            
            for (int i = 0; i < size; i++)
            {
                cardName[i] = "";
                cardPoint[i] = 0;
            }
            
            cardsDrawn = 0;
            handTotal = 0;
        }
        
        //Mutators
        void drawCard(string cardN, int cardP)
        {
            cardName[cardsDrawn] = cardN;
            cardPoint[cardsDrawn] = cardP;
            handTotal += cardPoint[cardsDrawn];
            cardsDrawn++;
        }
        
        void aceRule()
        {
            handTotal = 0;
            for (int i = 0; i < cardsDrawn; i++)
            {
                if (cardPoint[i] == 11) cardPoint[i] = 1;
                handTotal += cardPoint[i];
            }
        }
        
        //Accessors
        void printCards()
        {
            cout<<handTotal<<endl;
            for (int i = 0; i < cardsDrawn; i++)
            {
                cout<<left<<setw(13)<<cardName[i]<<" ";
                if (i+1 % 5 == 0) cout<<endl;
            }
            cout<<endl;
        }
        
        void printFirst()
        {
            cout<<cardPoint[0]<<" + ?"<<endl;
            cout<<left<<setw(13)<<cardName[0]<<" ?"<<endl;
        }
        
        int getTotal() const
        { return handTotal; }
        
        //Destructor
        ~Hand()
        {
            delete [] cardName;
            delete [] cardPoint;
        }
};

#endif /* HAND_H */

