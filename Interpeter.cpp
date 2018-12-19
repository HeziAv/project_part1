//
// Created by hezi on 12/17/18.
//

#include "Interpeter.h"
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
    int string = 0;
    int number = 0;
    while (index != str.length()) {
        if (str[index] != ' ') {
            if(object == "bind"){
                break;
            }
            if((str[index] >= 65 && str[index]<= 90) || (str[index]>=  97 && str[index<=122])){
                string = 1;
                if(number == 1){
                    cout << "error" <<endl;
                    throw (0);
                }
                object.push_back(str[index]);
                index++;
                continue;
            } else if(str[index] >= 48 && str[index]<= 57){
                number = 1;
                if(string == 1){
                    cout << "error" <<endl;
                    throw (0);
                }
                object.push_back(str[index]);
                index++;
                continue;
            } else{
                if(object != ""){
                  listOfStrings.push_back(object);
                }
                object=str[index];
                listOfStrings.push_back(object);
                number = 0;
                string = 0;
                index++;
                object = "";
                continue;
            }
        }
        if(object == ""){
            index++;
            continue;
        }if(object == "bind"){
            break;
        }
        listOfStrings.push_back(object);
        object = "";
        number = 0;
        string = 0;
        index++;
     }
        while (str[index] == 32){
            index++;
        }
        listOfStrings.push_back(object);
        object = "";
        for (long i = index; i < str.length() ; ++i) {
            object.push_back(str[i]);
        }
        listOfStrings = miniLexer(listOfStrings);
        return listOfStrings;
}


list<string> Interpeter::miniLexer(list<string> ls) {
    list<string> newList;
    list<string>::iterator it;
    int flag = 0;
    for (it = ls.begin();it != ls.end();++it) {
        while(*it != "+" && *it != "-" && *it !="/" && *it !="*"){
            if(*it == "bind"){
                return ls;
            }
            newList.push_back(*it);
            ++it;
        }
            if(flag == 0){
                flag = 1;
                --it;
                newList.pop_back();
                string newString = "";
                newString = newString + *it;
                ++it;
                newString = newString + *it;
                ++it;
                newString = newString + *it;
                newList.push_back(newString);
            }else{
                list<string>::iterator iit = newList.end();
                --iit;
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




//    long index = 0;
//    list<string> listOfStrings;
//    string object;
//    string num;
//    int flag = 0;
//    while (index != str.length()) {
//        if (str[index] != ' ') {
//            if (str[index] == '=') {
//                flag = 1;
//                listOfStrings.push_back("=");
//                index++;
//            }
//            if(object == "bind"){
//                index++;
//                listOfStrings.push_back(object);
//                object = "";
//                for (long i = index; i < str.length() ; ++i) {
//                    object.push_back(str[i]);
//                }
//                listOfStrings.push_back(object);
//                return listOfStrings;
//            }
//            if(flag == 1){
//                switch (str[index]) {
//                    case '+':
//                        object.push_back(str[index]);
//                        index++;
//                        while (str[index] != 32) {
//                            object.push_back(str[index]);
//                            index++;
//                        }
//                        index++;
//                        continue;
//                    case '-':
//                        object.push_back(str[index]);
//                        index++;
//                        while (str[index] != 32) {
//                            object.push_back(str[index]);
//                            index++;
//                        }
//                        index++;
//                        continue;
//                    case '*':
//                        object.push_back(str[index]);
//                        index++;
//                        while (str[index] != 32) {
//                            object.push_back(str[index]);
//                            index++;
//                        }
//                        index++;
//                        continue;
//                    case '(':
//                        object.push_back(str[index]);
//                        index++;
//                        while (str[index] != 32) {
//                            object.push_back(str[index]);
//                            index++;
//                        }
//                        index++;
//                        continue;
//                    default:
//                        object.push_back(str[index]);
//                        index++;
//                        continue;
//                }
//            }
//            if (str[index] != '=') {
//                object.push_back(str[index]);
//                index++;
//                continue;
//            }
//        }
//        // remove redundant spaces
//        if(str[index+1] == 32){
//            index++;
//            continue;
//        }
//        if(flag == 1){
//            index++;
//            if (str[index] == '+') {
//                continue;
//            }
//            if (str[index] == '-') {
//                continue;
//            }
//            if (str[index] == '*') {
//                continue;
//            }
//            if (str[index] == '/') {
//                continue;
//            }
//        }
//        listOfStrings.push_back(object);
//        object = "";
//        index++;
//        continue;
//    }
//    listOfStrings.push_back(object);
//    return listOfStrings;
