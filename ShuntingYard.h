//
// Created by hezi on 12/19/18.
//

#ifndef PROJECT_PART1_SHUNTINGYARD_H
#define PROJECT_PART1_SHUNTINGYARD_H


using namespace std;

#include <iostream>
#include "Expression.h"
#include <vector>

class ShuntingYard {
    vector<Expression*> eraseLs;
public:
    int getPriority(string C);
    vector<string>  infixToPostfix(string s);
    Expression* stringToExpression(vector<string> postfix);
    bool isOperator(char s);
    bool isOperatorS(string s);
    ~ShuntingYard();

};


#endif //PROJECT_PART1_SHUNTINGYARD_H
