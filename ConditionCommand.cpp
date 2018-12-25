//
// Created by hezi on 12/25/18.
//

#include <vector>
#include "ConditionCommand.h"
#include "ShuntingYard.h"


void ConditionCommand::setParameters(list<string> ls,Data* data1) {
    std::vector<string> v{std::begin(ls), std::end(ls)};
    ShuntingYard a;
    vector<string> postfix1, postfix2;
    string first = v[1];
    postfix1 = a.infixToPostfix(first);
    Expression *ExFirst = a.stringToExpression(postfix1);
    // in case one argumant
    if (v.size() == 2) {
        if (ExFirst->calculate(data1) > 0) {
            this->condition = true;
        } else {
            this->condition = false;
        }
    } else {
        string second = v[v.size() - 1];
        postfix2 = a.infixToPostfix(second);
        Expression *ExSecond = a.stringToExpression(postfix2);
        string c = v[2];
        double check = ExFirst->calculate(data1) - ExSecond->calculate(data1);
        if (v.size() == 4) {
            if (c == "<") {
                if (check < 0)
                    this->condition = true;
                else
                    this->condition = false;
            } else if (c == ">")
                if (check < 0)
                    this->condition = false;
                else
                    this->condition = true;
        } else if (v.size() == 5) {
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
                    this->condition = true;
                else
                    this->condition = false;
            } else if (c == "<=") {
                if (check <= 0)
                    this->condition = true;
                else
                    this->condition = false;
            }
        }
    }
}




