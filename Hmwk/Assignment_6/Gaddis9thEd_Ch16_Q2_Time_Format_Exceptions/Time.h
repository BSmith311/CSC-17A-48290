/* 
 * File:   Time.h
 * Author: Brandon
 *
 * Created on November 28, 2022
 */

#ifndef TIME_H
#define TIME_H

class Time{
protected:
    int hour;
    int min;
    int sec;
public:
    //Default Constructor
    Time()
        { hour = 0; min = 0; sec = 0; }
    
    //Constructor
    Time(int h, int m, int s)
        { hour = h; min = m; sec = s; }
    
    //Accessor functions
    //int getHour() const (Overwritten by MilTime)
        //{ return hour; }
    
    int getMin() const
        { return min; }
    
    int getSec() const
        { return sec; }
};

#endif /* TIME_H */

