//
// Created by hezi on 12/17/18.
//

#include "Minus.h"



double Minus::calculate(map<string,double> SymTbl) {
    return ((this->left)->calculate(SymTbl) - (this->right)->calculate(SymTbl));
}