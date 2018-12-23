//
// Created by hezi on 12/17/18.
//

#include "Neg.h"

Neg::Neg(Expression *ex) {
    this->ex = ex;
}


double Neg::calculate(Data* data) {
    return -this->ex->calculate(data);
}