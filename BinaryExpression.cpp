//
// Created by hezi on 12/16/18.
//

#include "BinaryExpression.h"
#include "Expression.h"


BinaryExpression ::BinaryExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

