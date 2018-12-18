//
// Created by hezi on 12/17/18.
//

#include "Minus.h"


Minus::Minus(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}


double Minus::calculate() {
    return (this->left->calculate() - this->right->calculate());
}