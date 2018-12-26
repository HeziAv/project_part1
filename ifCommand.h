//
// Created by hezi on 12/25/18.
//

#ifndef PROJECT_PART1_IFCOMMAND_H
#define PROJECT_PART1_IFCOMMAND_H


#include <list>
#include "Data.h"
#include "Command.h"
#include "ConditionCommand.h"

class ifCommand : public Command {
    Data* data;
    string first;
    string second;
    bool isAbind;
protected:
    list<string> conditionLine;
    ConditionCommand cond;
    list<string> commands;

public:
    ifCommand(Data* data) : cond(data){
        this->data=data;
    }
    virtual double doCommand(Data* data);
    virtual void setParameters(list<string> ls,Data* data1);
    virtual void setParameters(list<string> ls);
    virtual int parameterAmount(){};
};



#endif //PROJECT_PART1_IFCOMMAND_H
