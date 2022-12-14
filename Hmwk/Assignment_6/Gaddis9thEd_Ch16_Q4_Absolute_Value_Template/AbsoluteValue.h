/* 
 * File:   AbsoluteValue.h
 * Author: Brandon
 *
 * Created on November 28, 2022
 */

#ifndef ABSOLUTEVALUE_H
#define ABSOLUTEVALUE_H
#include <math.h>

template <class AbsoluteValue>
AbsoluteValue abs(AbsoluteValue number)
{
    return fabs(number);
}

#endif /* ABSOLUTEVALUE_H */

