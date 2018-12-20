//
// Created by hezi on 12/19/18.
//

#ifndef PROJECT_PART1_DATA_H
#define PROJECT_PART1_DATA_H


#include "ExpressionCommand.h"

class Data {
    map<string,double> SymTbl;
    map<string,string> bindMap;


public:
    Data(map<string,double> SymTbl,map<string,string> bindMap){};
    map<string,double> getSymTbl();
    map<string,string> getbindMap();
    void setSymTbl(string first, double second);
    void setbindMap(string first,string second);

};


#endif //PROJECT_PART1_DATA_H
