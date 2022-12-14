/* 
 * File:   MilTime.h
 * Author: Brandon
 *
 * Created on November 28, 2022
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime : public Time{
private:
    int milHours;
    int milSeconds;
public:
    //Default Constructor
    MilTime()
        { milHours = 0; milSeconds = 0; }
    
    //Constructor
    MilTime(int h, int s)
        { milHours = h; milSeconds = s; }
    
    //Mutator functions
    void setTime()
        { if (milHours > 1259) hour = ((milHours / 100) - 12);
          else if (milHours < 100) hour = ((milHours /100) + 12);
          else hour = (milHours / 100); 
          min = (milHours % 100); 
          sec = (milSeconds); }
    
    //Accessor functions
    int getHour() const
        { return milHours; }
    
    int getStandHr() const
        {return hour; }
};

#endif /* MILTIME_H */

