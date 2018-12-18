//
// Created by hezi on 12/17/18.
//

#include "Interpeter.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

list<string> Interpeter::lexer(string str) {
    long index = 0;
    list<string> listOfStrings;
    string object;
    string num;
    int flag = 0;
    while (index != str.length()) {
        if (str[index] != ' ') {
            if (str[index] == '=') {
                flag = 1;
                listOfStrings.push_back("=");
                index= index +2;
            }
            if(object == "bind"){
                flag = 3;
                index++;
                listOfStrings.push_back(object);
                object = "";
                for (long i = index; i < str.length() ; ++i) {
                    object.push_back(str[i]);
                }
                listOfStrings.push_back(object);
                return listOfStrings;
            }
            if(flag == 1){
                switch (str[index]) {
                    case '+':
                        object.push_back(str[index]);
                        index++;
                        while (str[index] != 32) {
                            object.push_back(str[index]);
                            index++;
                        }
                        index++;
                        continue;
                    case '-':
                        object.push_back(str[index]);
                        index++;
                        while (str[index] != 32) {
                            object.push_back(str[index]);
                            index++;
                        }
                        index++;
                        continue;
                    case '*':
                        object.push_back(str[index]);
                        index++;
                        while (str[index] != 32) {
                            object.push_back(str[index]);
                            index++;
                        }
                        index++;
                        continue;
                    case '(':
                        object.push_back(str[index]);
                        index++;
                        while (str[index] != 32) {
                            object.push_back(str[index]);
                            index++;
                        }
                        index++;
                        continue;
                    default:
                        object.push_back(str[index]);
                        index++;
                        continue;
                }
            }
            if (str[index] != '=') {
                object.push_back(str[index]);
                index++;
                continue;
            }
        }
        // remove redundant spaces
        if(str[index+1] == 32){
            index++;
            continue;
        }
        if(flag == 1){
            index++;
            if (str[index] == '+') {
                continue;
            }
            if (str[index] == '-') {
                continue;
            }
            if (str[index] == '*') {
                continue;
            }
            if (str[index] == '/') {
                continue;
            }
        }
        listOfStrings.push_back(object);
        object = "";
        index++;
        continue;
    }
    listOfStrings.push_back(object);
    return listOfStrings;
}