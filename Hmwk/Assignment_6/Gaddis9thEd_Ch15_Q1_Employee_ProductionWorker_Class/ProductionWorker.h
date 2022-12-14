/* 
 * File:   ProductionWorker.h
 * Author: Brandon
 *
 * Created on November 27, 2022
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker : public Employee
{
    private:
        int shift;
        float payRate;
        
    public:
        //Constructors
        ProductionWorker()
        {shift   = 0;
         payRate = 0.0;}
        
        ProductionWorker(int s, float p)
        {shift   = s;
         payRate = p;}
        
        //Mutators
        void setShift(int s)
        {shift = s;}
        void setPay(float p)
        {payRate = p;}
        
        //Accessors
        int getShift() const
        {return shift;}
        
        float getPay() const
        {return payRate;}
        
};

#endif /* PRODUCTIONWORKER_H */

