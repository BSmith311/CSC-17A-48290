/* 
 * File:   Stats.h
 * Author: Brandon
 *
 * Created on November 29, 2022
 */

#ifndef STATS_H
#define STATS_H
#include "Game.h"

class Stats : public Game
{
    private:
        static const int size = 22;
        string *pCardN1;
        string *pCardN2;
        string *dCardN;
        int *pCardP1;
        int *pCardP2;
        int *dCardP;
        int pTotal1;
        int pTotal2;
        int dTotal;
        int pDrawn1;
        int pDrawn2;
        int dDrawn;
        
    public:
        Stats()
        {
            pCardN1 = new string[size];
            pCardN2 = new string[size];
            dCardN  = new string[size];
            
            pCardP1 = new int[size];
            pCardP2 = new int[size];
            dCardP  = new int[size];
            
            for (int i = 0; i < size; i++)
            {
                pCardN1[i] = "";
                pCardN2[i] = "";
                dCardN[i]  = "";
                
                pCardP1[i] = 0;
                pCardP2[i] = 0;
                dCardP[i]  = 0;
            }
            
            pTotal1 = 0;
            pTotal2 = 0;
            dTotal  = 0;
        
            pDrawn1 = 0;
            pDrawn2 = 0;
            dDrawn  = 0;
        }
        
        //Mutators
        void addPCard1()
        {
            pCardN1[pDrawn1] = cardN[counter];
            pCardP1[pDrawn1] = cardP[counter];
            pTotal1 += pCardP1[pDrawn1];
            counter++;
            pDrawn1++;
        }
        void addPCard2()
        {
            pCardN2[pDrawn2] = cardN[counter];
            pCardP2[pDrawn2] = cardP[counter];
            pTotal2 += pCardP2[pDrawn2];
            counter++;
            pDrawn2++;
        }
        void addDCard()
        {
            dCardN[dDrawn] = cardN[counter];
            dCardP[dDrawn] = cardP[counter];
            dTotal += dCardP[dDrawn];
            counter++;
            dDrawn++;
        }
        
        //Accessors
        void printP1Hand()
        {
            cout<<pTotal1<<endl;
            for (int i = 0; i < pDrawn1; i++)
            {
                cout<<pCardN1[i]<<" ";
            }
            cout<<endl;
        }
        void printP2Hand()
        {
            cout<<pTotal2<<endl;
            for (int i = 0; i < pDrawn2; i++)
            {
                cout<<pCardN2[i]<<" ";
            }
            cout<<endl;
        }
        void printDHand()
        {
            cout<<dTotal<<endl;
            for (int i = 0; i < dDrawn; i++)
            {
                cout<<dCardN[i]<<" ";
            }
            cout<<endl<<endl;
        }
        
        //Destructor
        ~Stats()
        {
            delete [] pCardN1;
            delete [] pCardN2;
            delete [] dCardN;
            delete [] pCardP1;
            delete [] pCardP2;
            delete [] dCardP;
        }
};

#endif /* STATS_H */

