//
// Created by hezi on 12/17/18.
//

#include "Minus.h"



double Minus::calculate(Data* data) {
    return ((this->left)->calculate(data) - (this->right)->calculate(data));
}