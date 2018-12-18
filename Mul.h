//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_MUL_H
#define PROJECT_PART1_MUL_H


#include "BinaryExpression.h"

class Mul : public BinaryExpression {
    Expression* left;
    Expression* right;

public:
    Mul(Expression* left,Expression* right);
    virtual double calculate();

};

#endif //PROJECT_PART1_MUL_H
