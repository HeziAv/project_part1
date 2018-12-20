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
#include "connectCommand.h"
#include "EqualCommand.h"

using namespace std;

class Interpeter {
    Data* data;
    std::map<string,ExpressionCommand*> commandMap = {{"openDataServer",new ExpressionCommand(new OpenServerCommand(data

            ))},{"connect",new ExpressionCommand(new connectCommand(data))},{"=",new ExpressionCommand(new EqualCommand(data))}};
public:
    Interpeter(Data* data1){
        data=data1;
    }

    list<string> lexer(string str);
    list<string> miniLexer(list<string> ls);
    void parser (list<string> ls);
    bool isOperator(char s);

    };

#endif //PROJECT_PART1_INTERPETER_H
