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
    virtual void doCommand(){};
    virtual void setListOfString(list<string> ls){
        this->ls=ls;
    };

};


#endif //PROJECT_PART1_COMMAND_H
