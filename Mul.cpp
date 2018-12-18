//
// Created by hezi on 12/17/18.
//

#include "Mul.h"

Mul::Mul(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}


double Mul::calculate() {
    return (this->left->calculate() * this->right->calculate());
}