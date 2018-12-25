//
// Created by hezi on 12/25/18.
//

#ifndef PROJECT_PART1_IFCOMMAND_H
#define PROJECT_PART1_IFCOMMAND_H


#include <list>
#include "Data.h"
#include "Command.h"

class ifCommand : Command {
    list<string> ls;
    Data* data;
    string first;
    string second;
    bool isAbind;

public:
    ifCommand(Data* data){
        this->data=data;
    }
    virtual double doCommand(Data* data){};
    virtual void setParameters(list<string> ls){};
    virtual int parameterAmount(){};
};



#endif //PROJECT_PART1_IFCOMMAND_H
