//
// Created by hezi on 12/17/18.
//

#include "Div.h"



double Div::calculate() {
    return ((this->left)->calculate() / (this->right)->calculate());
}