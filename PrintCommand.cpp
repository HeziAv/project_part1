//
// Created by hezi on 12/23/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "ShuntingYard.h"

void PrintCommand::setParameters(list<string> ls, Data *data1) {
    this->first = "";
    list<string>::iterator it;
    // take the value that need to print
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (*it == "print") {
            continue;
        } else {
            if (*it == "\"") {
                ++it;
                this->Quotation_mark = true;
                this->first = *it;
                break;
            } else {
                this->first = *it;
                this->Quotation_mark = false;
                break;
            }
        }
    }
}

void PrintCommand::doCommand(Data *data) {
    // check if need to print the value or the variable with ""
    if (this->Quotation_mark == true) {
        cout << this->first << endl;
    } else {
//        std::map<string,double >::iterator it;
//        it = data->getSymTbl().find(this->first);
//        //if first is var
//        if (it != data->getSymTbl().end()){
//            double value = data->getSymTbl().find(this->first)->second;
//            cout << value << endl;
        if (data->has_key(this->first)) {
            double d;
            d = (*data)[this->first]->getVal();
            cout << d << endl;
        } else {
            // in case the first is expression
            ShuntingYard a;
            vector<string> postfix;
            postfix = a.infixToPostfix(this->first);
            Expression *ExFirst = a.stringToExpression(postfix);
            double value = ExFirst->calculate(data);
            cout << value << endl;
        }

    }
}
