//
// Created by hezi on 12/17/18.
//

#include "Plus.h"


double Plus::calculate(map<string,double> SymTbl) {
    return ((this->left)->calculate(SymTbl) + (this->right)->calculate(SymTbl));
}