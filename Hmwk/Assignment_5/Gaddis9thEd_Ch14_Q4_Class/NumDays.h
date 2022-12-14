/* 
 * File:   NumDays.h
 * Author: Brandon
 *
 * Created on November 22, 2022
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
    private:
        float hours;
        float days;
        
    public:
        NumDays(float h)
        {hours = h;}
        
        //Mutator
        void setDays()
        {days = (hours/8);}
        
        float Addition(float h1, float h2)
        {return (h1+h2);}
        
        float Subtraction(float h1, float h2)
        {return (h1-h2);}
        
        void Increment()
        {hours++;}
        
        void Decrement()
        {hours--;}
        
        //Accessor
        float getHours() const
        {return hours;}
        
        float getDays() const
        {return days;}
};

#endif /* NUMDAYS_H */

