//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_OPENSERVERCOMMAND_H
#define PROJECT_PART1_OPENSERVERCOMMAND_H


#include "Command.h"
#include "Data.h"
#include <iostream>
#include <vector>

using namespace std;


class OpenServerCommand : public Command {
    string first;
    string second;
    int SocketId{};
    Data* data;

public:
    explicit OpenServerCommand(Data* data){
        this->data=data;
    };

    void doCommand(Data* data);

    void setParameters(list<string> ls,Data* data1) override;


    int getSocketId();
    void setSocketId(int var);
    static void* server_Sock(int port, Data* data) ;
    static list<double> split(string);
//    void exit(Data *data1);
};




#endif //PROJECT_PART1_OPENSERVERCOMMAND_H
