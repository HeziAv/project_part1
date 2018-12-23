//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_MINUS_H
#define PROJECT_PART1_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {

public:
    Minus(Expression* left,Expression* right):BinaryExpression(left,right){}

    virtual double calculate(Data* data);

};


#endif //PROJECT_PART1_MINUS_H
