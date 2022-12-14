/* 
 * File:   Total.h
 * Author: Brandon
 *
 * Created on November 28, 2022
 */

#ifndef TOTAL_H
#define TOTAL_H

template <class T>
T total(int n)
{
    T sum = 0;
    T value;
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter value "<<(i+1)<<": ";
        cin>>value;
        sum += value;
    }
    return sum;
}

#endif /* TOTAL_H */

