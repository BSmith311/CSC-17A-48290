/* 
 * File:   Game.h
 * Author: Brandon
 *
 * Created on November 29, 2022
 */

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
using namespace std;

class Game
{
    protected:
        static const int deckSize = 66;
        string *cardN;
        int *cardP;
        int counter;
        
    public:
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
        
        //Accessors
        
        
        //Destructor
        ~Game()
        {
            delete [] cardN;
            delete [] cardP;
        }
};


#endif /* GAME_H */

