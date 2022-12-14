/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: Brandon
 *
 * Created on November 28, 2022, 12:31 PM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay : public GradedActivity
{
private:
    int grammar;
    int spelling;
    int length;
    int content;
public:
    //Default constructor
    Essay()
    { grammar = 0; spelling = 0; length = 0; content = 0; }
    
    //Constructor
    Essay(int g, int s, int l, int c)
    { grammar = g; spelling = s; length = l; content = c; }
    
    //Mutator
    void setScore()
    { score = (grammar + spelling + length + content); }
};

#endif /* ESSAY_H */

