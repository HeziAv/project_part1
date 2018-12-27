//
// Created by gad on 12/27/18.
//

#ifndef PROJECT_PART1_VARCOMMAND_H
#define PROJECT_PART1_VARCOMMAND_H


#include "Command.h"

class varCommand : public Command {
string first;
Data* data;

public:
    varCommand(Data* data){
        this->data=data;
    }
    double doCommand(Data *data) {
        Variable *variable = new Variable;
        variable->setVal(0.0);
        variable->setIsBound(false);
        variable->setPath("");
        data->addToNewTable(this->first, variable);
    };

    void setParameters(list<string> ls, Data *data1) {
        list<string>::iterator iterator;
        for (iterator = ls.begin(); iterator != ls.end(); ++iterator) {
            if (*iterator!="var"){
                first = *iterator;
                break;
            }
        }
    };

//    int parameterAmount() {};
};


#endif //PROJECT_PART1_VARCOMMAND_H
