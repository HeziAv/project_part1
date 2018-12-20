//
// Created by gad on 12/20/18.
//

#include "EqualCommand.h"
#include "ShuntingYard.h"
//check


struct MyParams {
    int port;
    Data* data;
};


double EqualCommand::doCommand() {
    setParameters(this->ls);
    // check if there is bind
    if(this->isAbind == true) {
        map<string, string> bindMap;
        bindMap = this->data->getbindMap();
        if (bindMap.count(this->first) > 0) {
            this->data->setbindMap(this->first,this->second);
        } else {
            this->data->getbindMap().insert(std::pair<string, string>(this->first, this->second));
        }
    }else {
        map<string, double> symMap;
        symMap = this->data->getSymTbl();
        ShuntingYard a;
        vector<string> postfix;
        postfix = a.infixToPostfix(this->second);
        Expression *ExFirst = a.stringToExpression(postfix);
        map<string, double> SymTbl;
        double sec = ExFirst->calculate(SymTbl);
        if (symMap.count(this->first) > 0) {
            this->data->setSymTbl(this->first, sec);
        } else {
            this->data->getSymTbl().insert(std::pair<string, double>(this->first, sec));
        }
    }
    return 3;
}



int EqualCommand::parameterAmount() {
    return 2;
}

void EqualCommand::setParameters(list<string> ls) {
    list<string>::iterator it;
    int i = 0;
    if(ls.size() > 5 || ls.size()<3){
        cout<<"error"<<endl;
        throw 0;
    }
    for (it = ls.begin(); it != ls.end(); ++it) {
        if(*it == "var"){
            it++;
            this->first = *it;
            i = 1;
        }
        if(*it == "bind"){
           this->isAbind = true;
           continue;
        }
        if(*it == "="){
            if(this->isAbind == true){
                ++it;
                this->second = *it;
            } else{
                this->second = *it;
            }
            i = 2;
        }
    }
    if(i != 2){
        cout<<"error"<<endl;
        throw 0;
    }
}
