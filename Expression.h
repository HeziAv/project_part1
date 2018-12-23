
//
// Created by hezi on 12/17/18.
//

#ifndef PROJECT_PART1_EXPRESSION_H
#define PROJECT_PART1_EXPRESSION_H
#include "Expression.h"
#include "Data.h"
#include <string>
#include <iostream>
#include <iterator>
#include <map>
using namespace std;


class Expression {

public:
    //virtual double calculate()=0;
    virtual double calculate(Data* data)=0;

};


#endif //PROJECT_PART1_EXPRESSION_H
