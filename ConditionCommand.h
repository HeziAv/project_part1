//
// Created by hezi on 12/25/18.
//

#ifndef PROJECT_PART1_CONDITIONCOMMAND_H
#define PROJECT_PART1_CONDITIONCOMMAND_H

#include "Command.h"
#include "Data.h"
#include "ExpressionCommand.h"

class ConditionCommand :public Command{
    Data *data;
    bool condition;
    list<string> parameters;


public:
    ConditionCommand(Data *data){
        this->data=data;
    }

    virtual double doCommand(Data *data2){};
    virtual void setParameters(list<string> ls, Data* data1);
    virtual int parameterAmount(){};
    bool isTrue();
};


#endif //PROJECT_PART1_CONDITIONCOMMAND_H
