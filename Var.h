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
    Var(string s){
        this->str = s;
    }

    virtual double calculate(Data* data){
        double d;



        // the key exit in the map
        if(data->getSymTbl().count(str)){
            d = data->getSymTbl().find(str)->second;
        }else{
           throw 0;
        }
        return d;
    }

    string getVar(){
        return this->str;
    }

};






#endif //PROJECT_PART1_VAR_H
