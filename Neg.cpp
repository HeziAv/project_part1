//
// Created by hezi on 12/17/18.
//

#include "Neg.h"


double Neg::calculate(Data* data) {
    return -(this->ex->calculate(data));
}