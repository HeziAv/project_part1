//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_COMMAND_H
#define PROJECT_PART1_COMMAND_H
#include <string>
#include <list>
using namespace std;


class Command {
    list<string> ls;
public:
    virtual double doCommand(){};
    virtual void setParameters(list<string> ls){};
    virtual int parameterAmount(){};

};


#endif //PROJECT_PART1_COMMAND_H
