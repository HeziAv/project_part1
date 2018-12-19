#include <cctype>
#include <algorithm>
#include <bits/stdc++.h>
#include "ShuntingYard.h"
#include "Number.cpp"
#include "Minus.cpp"
#include "Plus.cpp"
#include "Mul.cpp"
#include "Div.cpp"
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
    vector<string>  output;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if(!isOperator(s[i]) && s[i]!= '(' && s[i]!= ')'){
            string param = "";
            param.push_back(s[i]);
            output.push_back(param);
        }

            // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')
            stack.push("(");

            // If the scanned character is an ‘)’, pop and to output string from the stack
            // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
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
            string temp;
            temp.push_back(s[i]);
            while(stack.top() != "N" && getPriority(temp) <= getPriority(stack.top()))
            {
                string c = stack.top();
                stack.pop();
                output.push_back((c));
            }
            temp = "";
            temp.push_back(s[i]);
            stack.push(temp);
        }
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

Expression* ShuntingYard::stringToExpression(vector<string> postfix){
    stack<Expression*> stack;

    for (int i = 0; i < postfix.size(); ++i){

        if(!isOperatorS(postfix[i])){
            stack.push(new Number(stod(postfix[i])));
        }
        else {
            Expression* right = stack.top();
            stack.pop();
            Expression* left = stack.top();
            stack.pop();
            switch (postfix[i][0]){
                case '+':
                    stack.push(new Plus(left,right)) ;
                    break;
                case '-':
                    stack.push(new Minus(left,right)) ;
                    break;
                case '/':
                    stack.push(new Div(left,right)) ;
                    break;
                case '*':
                    stack.push(new Mul(left,right)) ;
                    break;
            }

        }
    }
    Expression* result = stack.top();
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