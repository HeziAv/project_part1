//
// Created by gad on 12/20/18.
//

#ifndef PROJECT_PART1_EQUALCOMMAND_H
#define PROJECT_PART1_EQUALCOMMAND_H


#include "Command.h"
#include "Data.h"
//check

class EqualCommand : public Command{
    list<string> ls;
    Data* data;
    string first;
    string second;
    bool isAbind;
    bool isVar;


public:
    EqualCommand(Data* data){
            this->data=data;
    }
    virtual double doCommand(Data* data);
    virtual void setParameters(list<string> ls,Data* data1);
    virtual int parameterAmount();
};


#endif //PROJECT_PART1_EQUALCOMMAND_H
