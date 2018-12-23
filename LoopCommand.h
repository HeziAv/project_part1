//
// Created by hezi on 12/20/18.
//

#ifndef PROJECT_PART1_LOOPCOMMAND_H
#define PROJECT_PART1_LOOPCOMMAND_H


#include "Command.h"
#include "Data.h"

class LoopCommand : public Command {
    Data* data;


public:
    virtual double doCommand();
    virtual void setParameters(list<string> ls);
    virtual int parameterAmount();
};


#endif //PROJECT_PART1_LOOPCOMMAND_H
