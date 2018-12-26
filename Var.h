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

    virtual double calculate(Data *data) {
        double d;

        if (this->str[0] == '-') {
            this->str.erase(str.begin());
        }

        // the key exit in the map
        if (data->getSymTbl().count(str)) {
            d = data->getSymTbl().find(str)->second;
        } else if (data->getbindMap().count(str)){
            string str1;
            str1 = data->getbindMap().find(str)->second;
            if (data->getSymTbl().count(str1)){
                d = data->getSymTbl().find(str1)->second;
            }
        }
        else {
            throw 0;
        }
        return d;
    }

    string getVar() {
        return this->str;
    }

};


#endif //PROJECT_PART1_VAR_H
