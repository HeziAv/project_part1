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
#include <vector>
#include "Command.h"
#include "ExpressionCommand.h"
#include "OpenServerCommand.h"
#include "connectCommand.h"
#include "EqualCommand.h"
#include "PrintCommand.h"
#include "EnterCCommand.h"
#include "ConditionCommand.h"
#include "ifCommand.h"
#include "WhileCommand.h"
#include "SleepCommand.h"
#include "varCommand.h"

using namespace std;

class Interpeter {
    Data* data;
    std::map<string,ExpressionCommand*> commandMap = {{"openDataServer",new ExpressionCommand(new OpenServerCommand(data))},{"connect",new ExpressionCommand(new connectCommand(data))},{"=",new ExpressionCommand(new EqualCommand(data))},{"print",new ExpressionCommand(new PrintCommand(data))},{"Enterc",new ExpressionCommand(new EnterCCommand())},{"if",new ExpressionCommand(new ifCommand(data))}
            ,{"while",new ExpressionCommand(new WhileCommand(data))},{"sleep",new ExpressionCommand(new SleepCommand(data))},{"var",new ExpressionCommand(new varCommand(data))}};
    static Interpeter* instance;
    Interpeter(Data* data1){
        data=data1;
    }
public:
    static Interpeter* getInstance(Data* data);

    list<string> lexer(istream& str);
    list<string> lexer(string str);
    list<string> miniLexer(list<string> ls);
    void parser (list<string> ls);
    bool isOperator(char s);
    bool isFixTokenS(string s);
    bool isFixToken(char s);


    void exit(Data *data1) {
        //close the sockets
        close(data1->getSokcetServer());
        close(data1->getSocketConnect());

        //go over the maps and clear them
        map<string, Variable*>::iterator iterator;
        for (iterator = data->getNewTbl().begin(); iterator != data->getNewTbl().end(); ++iterator) {
            delete (iterator->second);
        }
        data->getNewTbl().clear();
    }

    ~Interpeter(){
        map<string,ExpressionCommand*>::iterator iterator1;
        for (iterator1 = commandMap.begin(); iterator1 != commandMap.end(); ++iterator1) {
            delete (iterator1->second);
        }
        data->getNewTbl().clear();
    }

    };

#endif //PROJECT_PART1_INTERPETER_H
