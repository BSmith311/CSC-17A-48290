/* 
 * File:   MinMax.h
 * Author: Brandon
 *
 * Created on November 28
 */

#ifndef MINMAX_H
#define MINMAX_H

template <class Min>
Min min(Min &x, Min &y)
{
    if (x < y) return x;
    else return y;
}

template <class Max>
Max max(Max &x, Max &y)
{
    if (x > y) return x;
    else return y;
}

#endif /* MINMAX_H */

