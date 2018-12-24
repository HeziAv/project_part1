//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_UNARYEXPRESSION_H
#define PROJECT_PART1_UNARYEXPRESSION_H


#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression* ex;

public:
    UnaryExpression(Expression* ex);
    UnaryExpression(){};
    virtual double calculate(Data* data)=0;


};


#endif //PROJECT_PART1_UNARYEXPRESSION_H
