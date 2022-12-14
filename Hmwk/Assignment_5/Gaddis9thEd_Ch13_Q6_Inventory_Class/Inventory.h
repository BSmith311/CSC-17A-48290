/* 
 * File:   Inventory.h
 * Author: Brandon
 *
 * Created on November 22, 2022
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory{
    private:
        int itemNumber;
        int quantity;
        float cost;        
        float totalCost;
        
    public:
        //Constructors
        Inventory()
        {
            itemNumber = 0;
            quantity = 0;
            cost = 0;
            totalCost = 0;
        }
        
        Inventory(int n, int q, float c, float t)
        {
            setItemNumber(n);
            setQuantity(q);
            setCost(c);
            setTotalCost(t);
        }
        
        //Mutators
        void setItemNumber(int n)
        {itemNumber = n;}
        void setQuantity(int q)
        {quantity = q;}
        void setCost(float c)
        {cost = c;}
        void setTotalCost(float t)
        {totalCost = t;}
        
        //Accessors
        int getItemNumber() const
        {return itemNumber;}
        int getQuantity() const
        {return quantity;}
        float getCost() const
        {return cost;}
        float getTotalCost() const
        {return totalCost;}
};

#endif /* INVENTORY_H */

