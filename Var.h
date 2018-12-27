//
// Created by gad on 12/18/18.
//

#ifndef PROJECT_PART1_VAR_H
#define PROJECT_PART1_VAR_H

#include "Expression.h"
#include <string>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

class Var : public Expression {
protected:
    string str;


public:
    Var(string s) {
        this->str = s;
    }

    double calculate(Data *data) override {
        double d;
//
        if (data->has_key(str)) {
            d = (*data)[str]->getVal();
        }   else {
            // TODO key does not exist
            throw invalid_argument("key does exist");
        }
        return d;
    }

    string getVar() {
        return this->str;
    }

};


#endif //PROJECT_PART1_VAR_H
