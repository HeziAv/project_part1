//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_MUL_H
#define PROJECT_PART1_MUL_H


#include "BinaryExpression.h"

class Mul : public BinaryExpression {


public:

    Mul(Expression* left,Expression* right):BinaryExpression(left,right){}
    double calculate(map<string,double> SymTbl);

};

#endif //PROJECT_PART1_MUL_H
