//
// Created by hezi on 12/23/18.
//

#ifndef PROJECT_PART1_PRINTCOMMAND_H
#define PROJECT_PART1_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command {
        list<string> ls;
        Data* data;
        string first;
        bool Quotation_mark;

public:
        PrintCommand(Data* data){
            this->data=data;
        }
        virtual double doCommand(Data* data);
        virtual void setParameters(list<string> ls,Data* data);

    };



#endif //PROJECT_PART1_PRINTCOMMAND_H
