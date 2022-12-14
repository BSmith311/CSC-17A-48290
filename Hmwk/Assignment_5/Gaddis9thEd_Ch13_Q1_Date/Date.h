/* 
 * File:   Date.h
 * Author: Brandon Smith
 *
 * Created on November 21, 2022
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
};

#endif /* DATE_H */

