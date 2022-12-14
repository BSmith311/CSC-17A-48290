/* 
 * File:   Date.h
 * Author: Brandon
 *
 * Created on November 28, 2022
 */

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int month;
        int day;
        int year;
    public:
        void setDate(int,int,int);
        void printDate1();
        void printDate2();
        void printDate3();
        
        //Exceptions
        int InvalidDay(int d)
        {
            if (d < 1 or d > 31)
            {
                string exceptionString = "ERROR: Invalid day.";
                throw exceptionString;
            }
            
            return d;
        }
        
        int InvalidMonth(int m)
        {
            if (m < 1 or m > 12)
            {
                string exceptionString = "ERROR: Invalid month.";
                throw exceptionString;
            }
            
            return m;
        }
};

#endif /* DATE_H */

