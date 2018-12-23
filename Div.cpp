//
// Created by hezi on 12/17/18.
//

#include "Div.h"



double Div::calculate(Data* data) {
    return ((this->left)->calculate(data) / (this->right)->calculate(data));
}