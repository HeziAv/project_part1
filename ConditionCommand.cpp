//
// Created by hezi on 12/25/18.
//


#include <vector>
#include "ConditionCommand.h"
#include "ShuntingYard.h"

bool ConditionCommand::isTrue()
{
    return condition;
}

void ConditionCommand::setParameters(list<string> ls,Data* data1) {
    parameters = ls;
    std::vector<string> v{std::begin(ls), std::end(ls)};
    ShuntingYard a;
    vector<string> postfix1, postfix2;
    string first = v[1];
    postfix1 = a.infixToPostfix(first);
    Expression *ExFirst = a.stringToExpression(postfix1);
    // in case one argumant
    if (v.size() == 3) {
        if (ExFirst->calculate(data1) > 0) {
            this->condition = true;
        } else {
            this->condition = false;
        }
    } else {
        string second = v[v.size() - 2];
        postfix2 = a.infixToPostfix(second);
        Expression *ExSecond = a.stringToExpression(postfix2);
        string c = v[2];
        double check = ExFirst->calculate(data1) - ExSecond->calculate(data1);
        if (v.size() == 5) {
            if (c == "<") {
                if (check < 0)
                    this->condition = true;
                else
                    this->condition = false;
            } else if (c == ">") {
                if (check < 0)
                    this->condition = false;
                else
                    this->condition = true;
            } else{
                cout<<"error"<<endl;
                exit(1);
            }
        } else if (v.size() == 6) {
            c = c + v[3];
            if (c == "==") {
                if (check == 0)
                    this->condition = true;
                else
                    this->condition = false;
            } else if (c == "!=") {
                if (check != 0)
                    this->condition = true;
                else
                    this->condition = false;
            } else if (c == ">=") {
                if (check >= 0)
                    this->condition = false;
                else
                    this->condition = true;
            } else if (c == "<=") {
                if (check <= 0)
                    this->condition = true;
                else
                    this->condition = false;
            }
        } else{
            cout<<"error"<<endl;
            exit(1);
        }
    }
}





