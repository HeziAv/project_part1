//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_EXPRESSIONCOMMAND_H
#define PROJECT_PART1_EXPRESSIONCOMMAND_H


#include "Expression.h"
#include "Command.h"
#include "Data.h"

class ExpressionCommand : public Expression {
    Command* command;
    Data* data;

public:
    ExpressionCommand(Command* command);
    virtual double calculate(Data* data);

    virtual void setParameters1(list<string> ls,Data* data1){
        this->command->setParameters(ls,data1);
    }

    void setData(Data* data1){
        this->data=data1;
    }

    ~ExpressionCommand(){
        delete command;
    }


};





#endif //PROJECT_PART1_EXPRESSIONCOMMAND_H
