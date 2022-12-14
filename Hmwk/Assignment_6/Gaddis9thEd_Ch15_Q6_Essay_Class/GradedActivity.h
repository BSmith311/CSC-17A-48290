/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradedActivity.h
 * Author: Brandon
 *
 * Created on November 28, 2022, 12:28 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
protected:
    float score;
public:
    //Default constructor
    GradedActivity()
        { score = 0.0; }
    
    //Constructor
    GradedActivity(float s)
        { score = s; }
    
    //Mutator function
    //void setScore(float s) (Overwritten by Essay)
    //{ score = s; }
    
    //Accessor functions
    float getScore() const
        { return score; }
};

#endif /* GRADEDACTIVITY_H */

