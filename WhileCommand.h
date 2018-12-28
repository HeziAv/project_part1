//
// Created by hezi on 12/25/18.
//

#ifndef PROJECT_PART1_WHILECOMMAND_H
#define PROJECT_PART1_WHILECOMMAND_H

#include "ifCommand.h"

class WhileCommand : public ifCommand {
public:

    WhileCommand(Data* data) : ifCommand(data){
    }
    virtual void doCommand(Data* data);
};


#endif //PROJECT_PART1_WHILECOMMAND_H
