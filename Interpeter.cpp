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

list<string> Interpeter::lexer(string str) {
    long index = 0;
    list<string> listOfStrings;
    string object;
    string num;
    int number = 0;
    int var = 0;
    while (index != str.length()) {
        if (str[index] != ' ') {
            if (object == "bind") {
                break;
            }
            // check if the char is letter
            if ((str[index] >= 65 && str[index] <= 90) || (str[index] >= 97 && str[index] <= 122)) {

                if (object == "") {
                    var = 1; // start reading a variable
                }
                // error in case that is not fix
                if (var == 0 && number == 1) {
                    cout << "error" << endl;
                    throw 0;
                }
                object.push_back(str[index]);
                index++;
                continue;
                // check if the char is number
            } else if (str[index] >= 48 && str[index] <= 57) {
                if (object == "") {
                    number = 1;
                }
                object.push_back(str[index]);
                index++;
                continue;
            } else {
                if (number == 0 && var == 1) {
                    if (str[index] == '_') {
                        object.push_back(str[index]);
                        index++;
                        continue;
                    } else if (str[index] == ',') {}
                    else {
                        cout << "error" << endl;
                        throw 0;
                    }
                }
                if (number == 1) {
                    if (str[index] == '.') {
                        object.push_back(str[index]);
                        index++;
                        continue;
                    } else if (isOperator(str[index])) {}
                    else {
                        cout << "error" << endl;
                        throw 0;
                    }
                }
                if (object != "") {
                    listOfStrings.push_back(object);
                }
                if (isOperator(str[index])) {
                    --index;
                    if (str[index] != '-') {
                        cout << "error" << endl;
                        throw 0;
                    }
                    index++;
                }
                object = str[index];
                listOfStrings.push_back(object);
                number = 0;
                var = 0;
                index++;
                object = "";
                continue;
            }
        }
        if (object == "") {
            index++;
            continue;
        }
        if (object == "bind") {
            break;
        }
        listOfStrings.push_back(object);
        object = "";
        number = 0;
        var = 0;
        index++;
    }
    while (str[index] == 32) {
        index++;
    }
    listOfStrings.push_back(object);
    object = "";
    for (long i = index; i < str.length(); ++i) {
        object.push_back(str[i]);
    }
    listOfStrings = miniLexer(listOfStrings);
    //remove the char : , from the list
//    list<string>::iterator it;
//    for (it = listOfStrings.begin(); it != listOfStrings.end(); ++it) {
//        string temp = *it;
//        string newString = "";
//        if (*it == "bind") {
//            break;
//        }
//        for (long i = 0; i < temp.length(); ++i) {
//            if (temp.length() == 1) {
//                if (!(temp[i] >= 48 && temp[i] <= 57) ||
//                    ((temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122))) {
//                    cout << "error" << endl;
//                    throw 0;
//                }
//            }
//            if (temp[i] != ',') {
//                newString.push_back(temp[i]);
//            }
//        }
//    *it = newString;
//}
    return listOfStrings;
}


list<string> Interpeter::miniLexer(list<string> ls) {
    list<string> newList;
    list<string>::iterator it;
    int flag = 0;
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (*it != "+" && *it != "-" && *it != "/" && *it != "*") {
            if (*it == "bind") {
                return ls;
            }
            newList.push_back(*it);
            continue;
        }
        if (flag == 0) {
            flag = 1;
            --it;
            string temp = *it;
            if (temp == "=") {
                cout << "error" << endl;
                throw (0);
            }
            newList.pop_back();
            string newString = "";
            newString = newString + *it;
            ++it;
            newString = newString + *it;
            ++it;
            newString = newString + *it;
            newList.push_back(newString);

        } else {
            list<string>::iterator iit = newList.end();
            --iit;
            string check = *iit;
            if (check == "=") {
                cout << "error" << endl;
                throw (0);
            }
            string temp;
            temp = *iit;
            newList.pop_back();
            string newString = "";
            newString = temp + *it;
            ++it;
            newString = newString + *it;
            newList.push_back(newString);
        }

    }

    return newList;
}


void Interpeter::parser(list<string> ls) {
    list<string>::iterator it = ls.begin();
    int i = 0;
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (commandMap.find(*it) == commandMap.end()) {
            // not found
            continue;
        } else {
            // found
            ExpressionCommand *expressionCommand = commandMap.find(*it)->second;

            if (expressionCommand != NULL) {
                expressionCommand->setParameters1(ls);
//                expressionCommand->setData(data);


                expressionCommand->calculate(data->getSymTbl());
            }
            break;
        }
    }
}


bool Interpeter::isOperator(char s) {
    if (s == '+' || s == '-' || s == '/' || s == '*' || s == ',') {
        return true;
    }
    return false;
}