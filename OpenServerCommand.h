//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_OPENSERVERCOMMAND_H
#define PROJECT_PART1_OPENSERVERCOMMAND_H


#include "Command.h"
#include "Data.h"
#include <pthread.h>
#include <iostream>
using namespace std;


class OpenServerCommand : public Command {
    string first;
    string second;
    int SocketId;
    Data* data;

public:
    OpenServerCommand(Data* data){
        this->data=data;
    };
    virtual double doCommand();
    virtual void setParameters(list<string> ls);
    virtual int parameterAmount();
    static void* thread_func(void* threadid);
    int getSocketId();
    void setSocketId(int var);

};


#endif //PROJECT_PART1_OPENSERVERCOMMAND_H
