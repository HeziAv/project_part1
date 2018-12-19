//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_EXPRESSIONCOMMAND_H
#define PROJECT_PART1_EXPRESSIONCOMMAND_H


#include "Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
    Command* command;

public:
    ExpressionCommand(Command* command);
    virtual double calculate(map<string,double> SymTbl);

};


#endif //PROJECT_PART1_EXPRESSIONCOMMAND_H
