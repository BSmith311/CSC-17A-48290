/* 
 * File:   TimeOff.h
 * Author: Brandon
 *
 * Created on November 22, 2022, 8:33 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

class TimeOff{
    private:
        int maxSickDays;
        int sickTaken;
        int maxVacation;
        int vacTaken;
        int maxUnpaid;
        int unpaidTaken;
        
        string name;
        int number;
        
    public:
        TimeOff(int ms, int st, int mv, int vt, int mu, int ut, string n, int num)
        {maxSickDays = ms;
         sickTaken = st;
         maxVacation = mv;
         vacTaken = vt;
         maxUnpaid = mu;
         unpaidTaken = ut;
        
         name = n;
         number = num;}
        
        int getMaxSickDays() const
        {return maxSickDays;}
        int getSickTaken() const
        {return sickTaken;}
        int getMaxVacation() const
        {return maxVacation;}
        int getVacTaken() const
        {return vacTaken;}
        int getMaxUnpaid() const
        {return maxUnpaid;}
        int getUnpaidTaken() const
        {return unpaidTaken;}
        string getName() const
        {return name;}
        int getNumber() const
        {return number;}
        
        void PrintWarnings();
};

#endif /* TIMEOFF_H */

