//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_NUMBER_H
#define PROJECT_PART1_NUMBER_H


#include "Expression.h"

class Number : public Expression {
protected:
    double num;
public:
    Number(double n);
    virtual double calculate(Data* data);
    double getNumber();
};


#endif //PROJECT_PART1_NUMBER_H
