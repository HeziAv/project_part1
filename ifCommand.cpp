//
// Created by hezi on 12/25/18.
//

#include "ifCommand.h"
#include "Interpeter.h"

void ifCommand::doCommand(Data* data)
{
    if (this->cond.isTrue() == true) /////// cond.isTrue())
    {
        Interpeter* inn = Interpeter::getInstance(data);
        list<string>::iterator it = commands.begin();
        for (; it != commands.end(); ++it) {
            if (*it == "}")
                break;
            inn->parser(inn->lexer(*it));
        }
    }
}

void ifCommand::setParameters(list<string> ls,Data* data1)
{
    data = data1;
    setParameters(ls);
}
void ifCommand::setParameters(list<string> ls)
{
    Interpeter* inn = Interpeter::getInstance(data);
    list<string>::iterator it = ls.begin();
    list<string> lss;
    this->conditionLine = inn->lexer(*it);
    cond.setParameters(this->conditionLine, data);
    ++it;
    for (; it != ls.end(); ++it) {
        if (*it == "}")
            break;
        commands.push_back(*it);
    }
}
