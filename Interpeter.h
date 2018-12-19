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
using namespace std;

class Interpeter {

public:
    list<string> lexer(string str);
    list<string> miniLexer(list<string> ls);
};

#endif //PROJECT_PART1_INTERPETER_H
