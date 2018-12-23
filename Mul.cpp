//
// Created by hezi on 12/17/18.
//

#include "Mul.h"



double Mul::calculate(Data* data) {
    return ((this->left)->calculate(data) * (this->right)->calculate(data));
}