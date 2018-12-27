//
// Created by gad on 12/26/18.
//

#ifndef PROJECT_PART1_VARIABLE_H
#define PROJECT_PART1_VARIABLE_H

#include <string>

using namespace std;

class Variable {
    string path;
    double val;
    bool isBound; //# same as, path.isempty()
public:
    Variable(){
        this->path="";
        this->val=0;
        this->isBound=false;
    }

    void setVal(double v){
        val=v;
    }
    void setPath(string s){
        path=s;
    }
    void setIsBound(bool t){
        isBound=t;
    }

    double getVal(){
        return val;
    }
    string getPath(){
        return path;
    }
    bool getIsBound(){
        return isBound;
    }

    ~Variable() = default;



};


#endif //PROJECT_PART1_VARIABLE_H


