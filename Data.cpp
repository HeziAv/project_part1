//
// Created by hezi on 12/19/18.
//

#include "Data.h"

map<string,double> Data::getSymTbl() {
    return this->SymTbl;
}

map<string,string>* Data::getbindMap() {
    return this->bindMap;
}

void Data::setSymTbl(string first, double second) {

    this->SymTbl.insert(std::pair<string, double>(first, second));
}

void Data::setSymTbl3(map<string,double> x) {

    this->SymTbl=x;
}

void Data::setbindMap(string first,string second) {
    this->bindMap->insert(std::pair<string, string>(first, second));

}