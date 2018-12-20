//
// Created by hezi on 12/19/18.
//

#include "Data.h"

map<string,double> Data::getSymTbl() {
    return this->SymTbl;
}

map<string,string> Data::getbindMap() {
    return this->bindMap;
}

void Data::setSymTbl(string first, double second) {
    this->SymTbl[first] = second;
}

void Data::setbindMap(string first,string second) {
    this->bindMap[first] = second;
}