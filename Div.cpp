//
// Created by hezi on 12/17/18.
//

#include "Div.h"

Div::Div(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}


double Div::calculate() {
    return (this->left->calculate() / this->right->calculate());
}