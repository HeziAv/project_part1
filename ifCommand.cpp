//
// Created by hezi on 12/25/18.
//

#include "ifCommand.h"
#include "Interpeter.h"

double ifCommand::doCommand(Data* data)
{
    if (this->cond.isTrue() == true) /////// cond.isTrue())
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
    lss = inn->lexer(*it);
    cond.setParameters(lss, data);
    int i = 0;
    ++it;
    for (; it != ls.end(); ++it) {
        if (*it == "}")
            break;
        commands.push_back(*it);
    }
}
