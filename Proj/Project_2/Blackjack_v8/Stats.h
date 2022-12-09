/* 
 * File:   Stats.h
 * Author: Brandon
 *
 * Created on December 7, 2022, 1:18 PM
 */

#ifndef STATS_H
#define STATS_H

template <class S>
S winnings(S start, S end)
{
    if (end >= start)
    {
        cout<<"You won a total of $";
        return (end - start);
    }
    
    cout<<"You lost a total of $";
    return (start - end);
}

#endif /* STATS_H */

