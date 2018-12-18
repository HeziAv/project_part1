//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_PLUS_H
#define PROJECT_PART1_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression {
    Expression* left;
    Expression* right;

public:
    Plus(Expression* left,Expression* right);
    virtual double calculate();

};


#endif //PROJECT_PART1_PLUS_H
