#include <cctype>
#include <algorithm>
#include <bits/stdc++.h>
#include "ShuntingYard.h"
#include "Number.h"
#include "Minus.h"
#include "Plus.h"
#include "Mul.h"
#include "Div.h"
#include "Var.h"
#include "Neg.h"
#include <string>


using namespace std;


int ShuntingYard::getPriority(string C)
{
    if (C == "-" || C == "+")
        return 1;
    else if (C == "*" || C == "/")
        return 2;
    else if (C == "^")
        return 3;
    return 0;
}

vector<string> ShuntingYard::infixToPostfix(string s){
    stack<string> stack;
    stack.push("N");
    int l = s.length();
    vector<string> output;
    string param;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if(!isOperator(s[i]) && s[i]!= '(' && s[i]!= ')'){
            param.push_back(s[i]);
        }

            // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '('){
           output.push_back(param);
           stack.push("(");
           param = "";

        }

            // If the scanned character is an ‘)’, pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            output.push_back(param);
            param = "";
            while(stack.top() != "N" && stack.top() != "(")
            {
                string c = stack.top();
                stack.pop();
                output.push_back((c));
            }
            if(stack.top() == "(")
            {
                string c = stack.top();
                stack.pop();
            }
        }
            //If an operator is scanned
        else{
//            if(i == 0 && s[i] == '-'){
//               param = "-";
//               ++i;
//               for(i ;i<s.size();i++){
//                   if(!isOperator(s[i])){
//                       param = param + s[i];
//                   } else{
//                       --i;
//                       break;
//                   }
//               }
//               output.push_back(param);
//               stack.push(param);
//               param = "";
//                continue;
//            }
            if(param != "")
            output.push_back(param);
            param = "";
            string temp = "";
            temp.push_back(s[i]);
            while(stack.top() != "N" && getPriority(temp) <= getPriority(stack.top()))
            {
                string c = stack.top();
                stack.pop();
                output.push_back((c));
            }
            stack.push(temp);
        }
    }
    if(param != ""){
        output.push_back(param);
        param = "";
    }
    //Pop all the remaining elements from the stack
    while(stack.top() != "N")
    {
        string c = stack.top();
        stack.pop();
        output.push_back((c));
    }
    return output;
}

Expression* ShuntingYard::stringToExpression(vector<string> postfix) {
    stack<Expression *> stack;
    Expression* ex;
    int flag = 0;
    // clear empty strings in the vector
    if(postfix[0] == ""){
        postfix.erase (postfix.begin());
    }
    for(int i = 0; i < postfix.size(); ++i){
        if(postfix[i] == "")
        postfix.erase (postfix.begin()+i);
    }
    for (int i = 0; i < postfix.size(); ++i) {
       int var = 0;
       int flagMinus = 0;
       if (!isOperatorS(postfix[i])) {
           for(int j = 0;j < (postfix[i].size());j++) {
               if(isdigit(postfix[i][j])) {
                   continue;
                   // it is a number, so do some code
               } else if(isalpha(postfix[i][j])) {
                   var = 1;
                   break;
                   // it is not a number, do something else
               }else if(postfix[i][0] == '-'){
                   flagMinus = 1;
                   continue;
               }
           }
           if(var == 0){
               ex = new Number(stod(postfix[i]));
               stack.push(ex);
               eraseLs.push_back(ex);
           }else{
               if(flagMinus == 1){
                   ex = new Neg(new Var(postfix[i]));
                   stack.push(ex);
                   eraseLs.push_back(ex);
               }
                ex = new Var(postfix[i]);
                stack.push(ex);
               eraseLs.push_back(ex);
           }
        } else {
           Expression *right = stack.top();
           stack.pop();
           Expression *left = stack.top();
           stack.pop();
            switch (postfix[i][0]) {
                case '+':
                    ex = new Plus(left, right);
                    stack.push(ex);
                    eraseLs.push_back(ex);
                    break;
                case '-':
                    ex = new Minus(left, right);
                    stack.push(ex);
                    eraseLs.push_back(ex);
                    break;
                case '/':
                    ex = new Div(left, right);
                    stack.push(ex);
                    eraseLs.push_back(ex);
                    break;
                case '*':
                    ex = new Mul(left, right);
                    stack.push(ex);
                    eraseLs.push_back(ex);
                    break;
            }

        }
    }
    Expression *result = stack.top();
    return result;
}

bool ShuntingYard::isOperator(char s){
    if (s == '+' || s == '-' || s == '/' || s == '*'){
        return true;
    }
    return false;
}

bool ShuntingYard::isOperatorS(string s){
    if (s == "+" || s == "-" || s == "/" || s == "*"){
        return true;
    }
    return false;
}

ShuntingYard::~ShuntingYard() {
    for(auto expression: eraseLs){
        delete(expression);
    }
}

