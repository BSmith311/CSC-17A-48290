/* 
 * File:   Game.h
 * Author: Brandon
 *
 * Created on December 5, 2022
 */

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Hand.h"
#include "Gamble.h"
using namespace std;

class Game
{
    protected:
        static const int deckSize = 66;
        string *cardN;
        int *cardP;
        int counter;
        
        
    public:
        Gamble gambling;
        Hand player1;
        Hand player2;
        Hand dealer;
        
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
        }
        
        //Mutators
        void setDeck(const int,ifstream&,string);
        void drawP1Card()
        {
            player1.drawCard(cardN[counter], cardP[counter]);
            counter++;
        }
        void drawP2Card()
        {
            player2.drawCard(cardN[counter], cardP[counter]);
            counter++;
        }
        void drawDCard()
        {
            dealer.drawCard(cardN[counter], cardP[counter]);
            counter++;
        }
        
        void splitHands();
        
        //Accessors
        void printHands();
        void printSplitHands();
        
        //Destructor
        ~Game()
        {
            delete [] cardN;
            delete [] cardP;
        }
};


#endif /* GAME_H */

