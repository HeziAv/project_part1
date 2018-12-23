//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_NEG_H
#define PROJECT_PART1_NEG_H


#include "UnaryExpression.h"

class Neg : public UnaryExpression {
    Expression* ex;

public:
    Neg(Expression* ex);
    double calculate(Data* data);

};


#endif //PROJECT_PART1_NEG_H
