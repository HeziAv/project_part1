//
// Created by hezi on 12/25/18.
//

#include "WhileCommand.h"
#include "Interpeter.h"

double WhileCommand::doCommand(Data* data)
{
    while (this->cond.isTrue())
    {
        Interpeter* inn = Interpeter::getInstance(data);
        list<string>::iterator it = commands.begin();
        ++it;
        for (; it != commands.end(); ++it) {
            if (*it == "}")
                break;
            inn->parser(inn->lexer(*it));
        }
    }
}
