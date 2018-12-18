//
// Created by hezi on 12/17/18.
//

#include "Neg.h"

Neg::Neg(Expression *ex) {
    this->ex = ex;
}


double Neg::calculate(map<string,double> SymTbl) {
    return -this->ex->calculate(SymTbl);
}