//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_CONNECTCOMMAND_H
#define PROJECT_PART1_CONNECTCOMMAND_H


#include "Command.h"

class connectCommand : public Command {
    string address;
    string port;

public:
    connectCommand(){};
    virtual double doCommand();
    virtual void setParameters(list<string> ls);
    virtual int parameterAmount();




};


#endif //PROJECT_PART1_CONNECTCOMMAND_H
