//
// Created by hezi on 12/17/18.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}


double Plus::calculate() {
    return (this->left->calculate() + this->right->calculate());
}