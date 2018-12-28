//
// Created by hezi on 12/25/18.
//

#include "WhileCommand.h"
#include "Interpeter.h"

void WhileCommand::doCommand(Data* data)
{
    while (this->cond.isTrue())
    {
        Interpeter* inn = Interpeter::getInstance(data);
        for (auto &command : commands) {
            if (command == "}")
                break;
            inn->parser(inn->lexer(command));
        }
        this->cond.setParameters(this->conditionLine,data);
    }
}
