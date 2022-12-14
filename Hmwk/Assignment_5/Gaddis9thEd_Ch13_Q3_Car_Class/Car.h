/* 
 * File:   Car.h
 * Author: Brandon
 *
 * Created on November 22, 2022
 */

#ifndef CAR_H
#define CAR_H

class Car{
    private:
        int yearModel;
        string make;
        int speed;
    
    public:
        //Constructor
        Car(int y, string m)
        {
            yearModel = y;
            make = m;
            speed = 0;
        }
        
        //Accessors
        int getYearModel() const
        {return yearModel;}
        string getMake() const
        {return make;}
        int getSpeed() const
        {return speed;}
        
        void accelerate()
        {speed += 5;}
        void brake()
        {speed -= 5;}
};

#endif /* CAR_H */

