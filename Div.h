//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_DIV_H
#define PROJECT_PART1_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression {


    Div(Expression* left,Expression* right):BinaryExpression(left,right){}
    virtual double calculate();

};

#endif //PROJECT_PART1_DIV_H
