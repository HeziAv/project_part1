//
// Created by gad on 12/23/18.
//

#ifndef PROJECT_PART1_ENTERCCOMMAND_H
#define PROJECT_PART1_ENTERCCOMMAND_H


#include <iostream>
#include "Command.h"

class EnterCCommand : public Command {

public:
    EnterCCommand(){
    };
    virtual double doCommand(Data* data){
        int i;
        std::cout << "enter a c" << std::endl;
        std::cin >> i ;
    }

    virtual void setParameters(list<string> ls){};
    virtual int parameterAmount(){};
};



};


#endif //PROJECT_PART1_ENTERCCOMMAND_H
