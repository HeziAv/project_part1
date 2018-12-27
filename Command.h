//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_COMMAND_H
#define PROJECT_PART1_COMMAND_H
#include <string>
#include <list>
#include "Data.h"

using namespace std;



class Command {
    Data* data;
    list<string> ls;
public:
    virtual double doCommand(Data* data){};
    virtual void setParameters(list<string> ls,Data* data1){};
    virtual ~Command() = default;

};


#endif //PROJECT_PART1_COMMAND_H
