//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_OPENSERVERCOMMAND_H
#define PROJECT_PART1_OPENSERVERCOMMAND_H


#include "Command.h"

class OpenServerCommand : public Command {
    virtual void doCommand();
    virtual void setListOfString(list<string> ls);
};


#endif //PROJECT_PART1_OPENSERVERCOMMAND_H
