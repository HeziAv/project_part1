//
// Created by hezi on 12/17/18.
//

#include "Mul.h"



double Mul::calculate() {
    return ((this->left)->calculate() * (this->right)->calculate());
}