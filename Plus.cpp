//
// Created by hezi on 12/17/18.
//

#include "Plus.h"


double Plus::calculate() {
    return ((this->left)->calculate() + (this->right)->calculate());
}