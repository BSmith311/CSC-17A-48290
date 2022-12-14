/* 
 * File:   Numbers.h
 * Author: Brandon
 *
 * Created on November 22, 2022
 */

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers{
    private:
        int number;
        
        //Static Arrays
        string lessThan20[20] = {"Zero", "One", "Two", "Three", "Four", "Five",
                                 "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                                 "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                 "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string moreThan20[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                                 "Seventy", "Eighty", "Ninety"};
        string hundred = " Hundred ";
        string thousand = " Thousand ";
        
    public:
        Numbers(int n)
        {number = n;}
        
        void print();
};

#endif /* NUMBERS_H */

