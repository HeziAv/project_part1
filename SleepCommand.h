//
// Created by hezi on 12/26/18.
//

#ifndef PROJECT_PART1_SLEEPCOMMAND_H
#define PROJECT_PART1_SLEEPCOMMAND_H


#include "Data.h"
#include "Command.h"


class SleepCommand : public Command {
        Data* data;
        string first;

        public:
        SleepCommand(Data* data){
            this->data=data;
        }
        virtual void doCommand(Data* data);
        virtual void setParameters(list<string> ls,Data* data);

 };





#endif //PROJECT_PART1_SLEEPCOMMAND_H
