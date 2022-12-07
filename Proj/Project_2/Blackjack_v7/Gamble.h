/* 
 * File:   Gamble.h
 * Author: Brandon
 *
 * Created on December 6, 2022
 */

#ifndef GAMBLE_H
#define GAMBLE_H

class Gamble
{
    private:
        float funds;
        float bet;
        float insurance;
        
    public:
        //Constructor
        Gamble()
        {
            funds = 0;
            insurance = 0;
            bet = 0;
        }
        
        //Mutators
        void setFunds(float f)
        {
            funds = f;
        }
        
        void setBet(float b)
        {
            bet = b;
            funds -= b;
        }
        
        void setInsurance(float i)
        {
            insurance = i;
            funds -= i;
        }
        
        void doubleBet()
        {
            funds -= bet;
            bet *= 2;
        }
        
        //Draw payout
        void payOut()
        {
            funds += bet;
        }
        
        //Insurance payout
        void payOut(float i)
        {
            funds += (i * 2);
        }
        
        //Win payout
        void payOut(float b, float p)
        {
            funds += (b * p);
        }
        
        //Accessors
        float getFunds() const
        { return funds; }
        
        float getBet() const
        { return bet; }
        
        float getInsurance() const
        { return insurance; }
        
        //Exceptions
        float BadBet(float b)
        {
            if (b > funds)
            {
                string exceptionString = "You can't afford that bet, get out of here!";
                throw exceptionString;
            }
            else if (b < 0)
            {
                string exceptionString = "That's not a valid bet, get out of here!";
                throw exceptionString;
            }
            
            return b;
        }
};

#endif /* GAMBLE_H */