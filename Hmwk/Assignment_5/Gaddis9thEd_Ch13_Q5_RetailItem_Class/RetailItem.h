/* 
 * File:   RetailItem.h
 * Author: Brandon
 *
 * Created on November 22, 2022
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

class RetailItem{
    private:
        string description;
        int unitsOnHand;
        float price;
        
    public:
        //Constructor
        RetailItem()
        {
            description = "";
            unitsOnHand = 0;
            price = 0;
        }
        
        //Mutators
        void setDescription(string d)
        {description = d;}
        void setUnits(int u)
        {unitsOnHand = u;}
        void setPrice(float p)
        {price = p;}
        
        //Accessors
        string getDescription() const
        {return description;}
        int getUnits() const
        {return unitsOnHand;}
        float getPrice() const
        {return price;}
};

#endif /* RETAILITEM_H */

