//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_OPENSERVERCOMMAND_H
#define PROJECT_PART1_OPENSERVERCOMMAND_H


#include "Command.h"

class OpenServerCommand : public Command {
    string first;
    string second;

public:
    OpenServerCommand(){};
    virtual void doCommand();
    virtual void setParameters(list<string> ls);
    virtual int parameterAmount();
};


#endif //PROJECT_PART1_OPENSERVERCOMMAND_H
