//
// Created by hezi on 12/23/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "ShuntingYard.h"

void PrintCommand ::setParameters(list<string> ls) {
    this->first = "";
    list<string>::iterator it;
    if(ls.size() != 2){
        cout << "error" <<endl;
        throw 0;
    }
    // take the value that need to print
    for (it = ls.begin(); it != ls.end(); ++it) {
        if(*it == "print"){
            continue;
        } else{
            this->first = *it;
        }
    }
    //check if need Quotation mark
    string temp = this->first;
    if(temp[0] == 34 && temp[temp.length()  - 1] == 34)
        this->Quotation_mark = true;
    else
        this->Quotation_mark = false;

}

double PrintCommand ::doCommand(Data *data) {
    if(this->Quotation_mark == true) {
        cout<<this->first<<endl;
    }else {
        ShuntingYard a;
        vector<string> postfix;
        postfix = a.infixToPostfix(this->first);
        Expression *ExFirst = a.stringToExpression(postfix);
        double value = ExFirst->calculate(data);
        cout << value << endl;
    }
}

int PrintCommand ::parameterAmount() {
    return 2;
}