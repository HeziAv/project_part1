//
// Created by hezi on 12/17/18.
//

#include "Minus.h"



double Minus::calculate() {
    return ((this->left)->calculate() - (this->right)->calculate());
}