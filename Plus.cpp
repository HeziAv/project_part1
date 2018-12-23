//
// Created by hezi on 12/17/18.
//

#include "Plus.h"


double Plus::calculate(Data* data) {



    return ((this->left)->calculate(data) + (this->right)->calculate(data));
}