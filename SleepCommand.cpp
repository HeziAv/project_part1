//
// Created by hezi on 12/26/18.
//

#include <unistd.h>
#include "SleepCommand.h"
#include "ShuntingYard.h"

void SleepCommand:: setParameters(list<string> ls,Data* data){
    list<string>::iterator it = ls.begin();
    ++it;
    this->first = *it;
}

void SleepCommand::doCommand(Data *data) {
    ShuntingYard a;
    vector<string> postfix;
    postfix = a.infixToPostfix(this->first);
    Expression *ExFirst = a.stringToExpression(postfix);
    double sec = ExFirst->calculate(data);
    sleep(1 / sec);
}