//
// Created by hezi on 12/16/18.
//

#ifndef PROJECT_PART1_BINARYEXPRESSION_H
#define PROJECT_PART1_BINARYEXPRESSION_H


#include <cmath>
#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* left;
    Expression* right;
    double numl;

public:
    BinaryExpression(Expression* left,Expression* right);
    BinaryExpression(){};
    virtual double calculate()=0;





};


#endif //PROJECT_PART1_BINARYEXPRESSION_H
