//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_UNARYEXPRESSION_H
#define PROJECT_PART1_UNARYEXPRESSION_H


#include "Expression.h"

class UnaryExpression : public Expression {
    Expression* ex;

public:
    UnaryExpression(Expression* ex);
    UnaryExpression(){};
    virtual double calculate(map<string,double> SymTbl)=0;


};


#endif //PROJECT_PART1_UNARYEXPRESSION_H
