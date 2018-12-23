//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_CONNECTCOMMAND_H
#define PROJECT_PART1_CONNECTCOMMAND_H


#include "Command.h"
#include "Data.h"

class connectCommand : public Command {
    string address;
    string port;
    Data* data;

public:

    connectCommand(Data* data){
        this->data=data;
    };
    virtual double doCommand(Data* data);
    virtual void setParameters(list<string> ls);
    virtual int parameterAmount();
};


#endif //PROJECT_PART1_CONNECTCOMMAND_H
