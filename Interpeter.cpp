//
// Created by hezi on 12/17/18.
//

#include "Interpeter.h"
#include "ExpressionCommand.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <regex>

//gad
using namespace std;

bool Interpeter:: isFixTokenS(string s){
    if (s == "=" || s == "," || s == "{" || s == "}" || s == "(" || s == ")" || s == """" || s == "<" || s == ">" ||
        s == "!" || s == "print" || s == "if" || s == "while" || s == "exit") {
        return true;
    }
    return false;
}


list<string> Interpeter::miniLexer(list<string> ls) {
    list<string> newList;
    string object;
    list<string>::iterator it;
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (*it != "+" && *it != "-" && *it != "/" && *it != "" && *it != "(") {
            if (*it == "while" || *it == "if") {
                return ls;
            }
            if(*it == ","){
                object = *it;
            }
            // in case of print
            if(*it == "print"){
                object = *it;
                newList.push_back(object);
                ++it;
                if(*it == "\""){
                    newList.push_back("\"");
                    string val;
                    for (it; it != ls.end() ; ++it) {
                        if(*it != "\""){
                            val = val + *it;
                        }
                    }
                    newList.push_back(val);
                    newList.push_back("\"");
                    return newList;
                }else{
                    --it;
                    continue;
                }
            }
            object = *it;
            newList.push_back(object);
            continue;
        }
        int flag = 0;
        if(*it == "("){
            object = "";
        }

        if (!isFixTokenS(object)) {
            newList.pop_back();
        }else{
            object = "";
        }
        while (it != ls.end()) {
            if (*it == "," || *it == "bind") {
                break;
            }
            if(*it == "=" || *it == "{" || *it == "}" || *it == "<" || *it == ">" || *it == "!"){
                --it;
                break;
            }
            if (*it == ")") {
                object = object + *it;
                ++it;
            }else{
                object = object + *it;
                ++it;
            }
        }
        newList.push_back(object);
        object = "";
        if (it == ls.end()) {
            break;
        }
    }
    return newList;
}

Interpeter* Interpeter::instance = NULL;

Interpeter* Interpeter::getInstance(Data* data)
{
    if (instance == NULL)
        instance = new Interpeter(data);
    return instance;
}

bool Interpeter::isOperator(char s){
    if (s == '+' || s == '-' || s == '/' || s == '*'){
        return true;
    }
    return false;
}

bool Interpeter:: isFixToken(char s){
    if (s == '=' || s == ',' || s == '{' || s == '}' || s == '(' || s == ')' || s == '"' || s == '<' || s == '>' ||
        s == '!') {
        return true;
    }
    return false;
}



list<string> Interpeter:: lexer(istream& stream)
{
    std::string line;
    list<string> ls;
    std::getline(stream, line);
    if (line[line.size() - 1] != '{')
    {
        ls = lexer(line);
        return ls;
    }
    ls.push_back(line);
    do
    {
        std::getline(stream, line);
        ls.push_back(line);
    }
    while (line[line.size() - 1] != '}'); // while we didn't read the "}"
    return ls;
}
list<string>Interpeter:: lexer(string str) {
    long count = 0;
    list<string> listOfStrings;
    string object;
    string num;
    int number = 0;
    int var = 0;
    for (long index = 0 ; index < str.length();index++) {
        if (str[index] != ' ') {
            if(object == "bind" || object == "while" || object == "if"){
                count = index;
                break;
            }
            // check if the char is letter
            if(isalpha(str[index])){
                if(object == ""){
                    var = 1; // start reading a variable
                }
                // error in case that is not fix
                if(var == 0 && number == 1){
                    cout<<"error"<<endl;
                    throw 0;
                }
                object.push_back(str[index]);
                continue;
                // check if the char is number
            } else if(isdigit(str[index])){
                if(object == ""){
                    number = 1;
                }
                object.push_back(str[index]);
                continue;
                // check if the char is operator
            } else if(isOperator(str[index])) {
                int checkIfOperatorBefore = index - 1;
                if(checkIfOperatorBefore == -1)
                    throw 0;
                // add zero before minus
               if(str[index] == '-') {
                   int z = 1;
                   while((str[checkIfOperatorBefore]) == 32 && checkIfOperatorBefore != -1){
                       ++z;
                       checkIfOperatorBefore = index - z;
                   }
                   if (isOperator(str[checkIfOperatorBefore]) || isFixToken(str[checkIfOperatorBefore])) {
                       if (object != "")
                           listOfStrings.push_back(object);
                       listOfStrings.push_back("0");
                       listOfStrings.push_back("-");
                       object = "";
                       var = 0;
                       number = 0;
                       continue;
                   }
               }
                if(object != "")
                    listOfStrings.push_back(object);
                object = "";
                object = str[index];
                listOfStrings.push_back(object);
                object = "";
                var = 0;
                number = 0;
                continue;
            }else{
                // check if the current object is var
                if(var == 1) {
                    if (str[index] == '_') {
                        object.push_back(str[index]);
                        continue;
                    }
                }
                // check if the current object is a number
                if(number == 1) {
                    if (str[index] == '.') {
                        object.push_back(str[index]);
                        continue;
                    } else if(isFixToken(str[index])) {
                        listOfStrings.push_back(object);
                        string s(1, str[index]);
                        listOfStrings.push_back(s);
                        number = 0;
                        var = 0;
                        object = "";
                        continue;
                    } else{
                        cout << "error" << endl;
                        throw 0;
                    }
                }if(isFixToken(str[index])){
                    if(object != "") {
                        listOfStrings.push_back(object);
                    }
                    object = str[index];
                    listOfStrings.push_back(object);
                    object = "";
                    var = 0;
                    number = 0;
                    continue;
                }
                else{
                    cout<<"wrong char"<<endl;
                    throw 0;
                }
            }
        }
        if(object == ""){
            continue;
        }if(object == "bind" || object == "while" || object == "if"){
            count = index;
            break;
        }
        listOfStrings.push_back(object);
        object = "";
        number = 0;
        var = 0;
    }
    if(object != ""){
        listOfStrings.push_back(object);
    }
    // build bind line
    if(object == "bind"){
        while(str[count] == 32) {
            count++;
        }
        string address;
        for(int i = count;i<str.length();i++){
            if(str[i] != '\"')
            address.push_back(str[i]);
        }
        listOfStrings.push_back(address);
        return listOfStrings;
    }
    // build condition line
    if(object == "if" || object == "while"){
        // clear white space
        while(str[count] == 32) {
            count++;
        }
        string address;
        for(int i = count;i<str.length();i++){
            if(str[i] == 32)
                continue;
            if(str[i] != '(' && str[i] != ')' && str[i] != '{') {
                while (!isFixToken(str[i])){
                    if(str[i] == 32){
                        i++;
                        continue;
                    }
                    address.push_back(str[i]);
                    i++;
                }
                if(address != "")
                listOfStrings.push_back(address);
                address = str[i];
                listOfStrings.push_back(address);
                address = "";
            }else{
                address = str[i];
                listOfStrings.push_back(address);
                address = "";
            }

        }
        return listOfStrings;
    }
    listOfStrings = miniLexer(listOfStrings);
    //remove the char : , from the list
    list<string>::iterator it;
    for (it = listOfStrings.begin();it != listOfStrings.end();++it) {
        string temp = *it;
        string newString = "";

        // check if in the string problem chars
        for (long i = 0; i < temp.length() ; ++i) {
            if(temp.length() == 1){
                if(!(isalpha(temp[0]) || isdigit(temp[0]) || isFixToken(temp[0]))){
                    cout<<"error"<<endl;
                    throw 0;
                }
            }
            if(temp[i] != ','){
                newString.push_back(temp[i]);
            }
        }
        *it = newString;
    }
    return listOfStrings;
}



void Interpeter::parser(list<string> ls) {
    if(!ls.empty()){

    list<string>::iterator it = ls.begin();
    bool commandWasRun = false;
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (commandMap.find(*it) == commandMap.end()) {
            // not found
            continue;
        } else {
            // found
            ExpressionCommand *expressionCommand = commandMap.find(*it)->second;

            if (expressionCommand != NULL) {
                expressionCommand->setData(data);
                expressionCommand->setParameters1(ls,data);
                expressionCommand->calculate(data);
            }
            commandWasRun = true;
            break;
        }
    }
    if (! commandWasRun)
    {
        it = ls.begin();
        list<string> firstList = lexer(*it);
        ExpressionCommand *expressionCommand = commandMap.find(*firstList.begin())->second;

        if (expressionCommand != NULL) {
            expressionCommand->setData(data);
            expressionCommand->setParameters1(ls,data);
            expressionCommand->calculate(data);
        }
    }
}
}

