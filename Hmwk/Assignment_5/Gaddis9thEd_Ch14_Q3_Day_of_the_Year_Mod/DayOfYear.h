/* 
 * File:   DayOfYear.h
 * Author: Brandon
 *
 * Created on November 22, 2022
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

class DayOfYear{
    private:
        string month;
        int day;
        
        //Static Array
        string months[12] = {"January", "February", "March", "April", "May",
                             "June", "July", "August", "September", "October",
                             "November", "December"};
        
    public:
        DayOfYear(string m, int d)
        {month = m;
         day = d;}
        
        void print();
};

#endif /* DAYOFYEAR_H */

