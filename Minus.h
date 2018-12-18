//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_MINUS_H
#define PROJECT_PART1_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
    Expression* left;
    Expression* right;

    Minus(Expression* left,Expression* right);
    virtual double calculate();

};


#endif //PROJECT_PART1_MINUS_H
