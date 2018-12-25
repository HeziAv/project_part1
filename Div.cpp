//
// Created by hezi on 12/17/18.
//

#include "Div.h"



double Div::calculate(Data* data) {
    if ((this->right)->calculate(data) != 0) {
    return ((this->left)->calculate(data) / (this->right)->calculate(data));
    }else{
        cout<<"cannot divide zero"<<endl;
        throw 0;
    }
}