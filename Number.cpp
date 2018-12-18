//
// Created by hezi on 12/17/18.
//

#include "Number.h"

Number::Number(double n) {
    this->num=n;
}

double Number::calculate(map<string,double> SymTbl){
    return this->num;
}

double Number::getNumber() {
    return this->num;
}
