//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_NEG_H
#define PROJECT_PART1_NEG_H


#include "UnaryExpression.h"

class Neg : public UnaryExpression {

public:
    Neg(Expression* ex):UnaryExpression(ex){};
    Neg(){}
    double calculate(Data* data);

};


#endif //PROJECT_PART1_NEG_H
