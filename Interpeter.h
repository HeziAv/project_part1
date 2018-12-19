//
// Created by hezi on 12/17/18.
//
#ifndef PROJECT_PART1_INTERPETER_H
#define PROJECT_PART1_INTERPETER_H
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <list>
#include <map>
#include "Command.h"
#include "ExpressionCommand.h"
#include "OpenServerCommand.h"

using namespace std;

class Interpeter {
    std::map<string,ExpressionCommand*> commandMap = {{"openDataServer",new ExpressionCommand(new OpenServerCommand())},{"connect",new ExpressionCommand(new connectCommand())}};
public:
    list<string> lexer(string str);
    list<string> miniLexer(list<string> ls);
    void parser (list<string> ls);
};

#endif //PROJECT_PART1_INTERPETER_H
