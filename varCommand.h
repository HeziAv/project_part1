//
// Created by gad on 12/27/18.
//

#ifndef PROJECT_PART1_VARCOMMAND_H
#define PROJECT_PART1_VARCOMMAND_H


#include "Command.h"

class varCommand : public Command {
string first;
Data* data;
Variable* var = new Variable;

public:
    varCommand(Data* data){
        this->data=data;
    }
    void doCommand(Data *data) {
        var->setVal(0);
        var->setIsBound(false);
        var->setPath("");
        data->addToNewTable(this->first, var);
    }

    void setParameters(list<string> ls, Data *data1) {
        list<string>::iterator iterator;
        for (iterator = ls.begin(); iterator != ls.end(); ++iterator) {
            if (*iterator!="var"){
                first = *iterator;
                break;
            }
        }
    }

    ~varCommand(){
        delete(var);
    };




//    int parameterAmount() {};
};


#endif //PROJECT_PART1_VARCOMMAND_H
