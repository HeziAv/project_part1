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

    virtual void setParameters1(list<string> ls){
        this->command->setParameters(ls);
    }

    virtual int parameterAmount(){
        return this->command->parameterAmount();
    }


};


#endif //PROJECT_PART1_EXPRESSIONCOMMAND_H
