//
// Created by hezi on 12/19/18.
//

#ifndef PROJECT_PART1_DATA_H
#define PROJECT_PART1_DATA_H

#include "Data.h"
#include "Variable.h"

using namespace std;

#include <map>
#include <mutex>


class Data {
    map<string, Variable*> newTbl;
    string global;
public:
    Data() = default;

    string getGlobal()  const {
        return global;
    }

    void setGlobal(string s)    {
        global = s;
    }
    void addToNewTable(const string &first, Variable* second) {
        newTbl[first] = second;
    }

    Variable* operator[](const string &key)    {
        if (newTbl.count(key) == 0) throw std::invalid_argument("no such key");
        return newTbl[key];
    }

    Variable* operator[](const string &key) const   {
        return newTbl.at(key);
    }

    bool has_key(const string& key) const {
        return newTbl.count(key) == 1;
    }


};


#endif //PROJECT_PART1_DATA_H
