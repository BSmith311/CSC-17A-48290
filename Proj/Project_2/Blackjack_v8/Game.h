/* 
 * File:   Game.h
 * Author: Brandon
 *
 * Created on December 7, 2022
 */

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
using namespace std;

class Game
{
    protected:
        static const int deckSize = 66;
        string *cardN;
        int *cardP;
        int counter;
        float totalGambled;
        vector<string> nextCard;
        
    public:
        //Gamble gambling;
        Hand hands[3];
        
        //Constructor
        Game()
        {
            cardN = new string[deckSize];
            cardP = new int[deckSize];
            for (int i = 0; i < deckSize; i++)
            {
                cardN[i] = "";
                cardP[i] = 0;
            }
            
            counter = 0;
            totalGambled = 0;
        }
        
        //Copy constructor
        Game(Game &obj)
        {
            cardN = obj.cardN;
            cardP = obj.cardP;
            totalGambled = obj.totalGambled;
        }
        
        //Mutators
        void setDeck(const int,ifstream&,string);
        
        void drawP1Card()
        {
            hands[0].drawCard(cardN[counter], cardP[counter]);
            counter++;
        }
        void drawP2Card()
        {
            hands[1].drawCard(cardN[counter], cardP[counter]);
            counter++;
        }
        void drawDCard()
        {
            hands[2].drawCard(cardN[counter], cardP[counter]);
            counter++;
        }
        
        void splitHands();
        
        //Accessors
        void printCards();
        
        void printSplitCards();
        
        float getTotalGambled() const
        { return totalGambled; }
        
        string getNextCard(int i) const
        { return nextCard[i]; }
        
        //Push function
        void pushFunction(string n)
        {
            nextCard.push_back(n);
        }
        
        //Pop function
        void popFunction()
        {
            nextCard.pop_back();
        }
        
        //Destructor
        virtual ~Game()
        {
            delete [] cardN;
            delete [] cardP;
        }
};


#endif /* GAME_H */

