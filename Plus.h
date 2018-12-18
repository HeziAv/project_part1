//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_PLUS_H
#define PROJECT_PART1_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression {

public:
    Plus(Expression* left,Expression* right):BinaryExpression(left,right){}
    double calculate(map<string,double> SymTbl);


};


#endif //PROJECT_PART1_PLUS_H
