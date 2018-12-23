//
// Created by hezi on 12/19/18.
//

#ifndef PROJECT_PART1_DATA_H
#define PROJECT_PART1_DATA_H

#include "Data.h"
using namespace std;
#include <map>


class Data {
    map<string,double> SymTbl;
    map<string,string> bindMap;
    int readSocket;
    int writeSocket;


public:
    Data(){
        map<string,double> SymTbl1 = {{"x",0}};
        this->SymTbl = SymTbl1;
        map<string,string> bindMap = {{"x","0"}};
        this->bindMap = bindMap;
        this->readSocket=0;
        this->writeSocket=0;

    }

    map<string,double> getSymTbl();
    map<string,string> getbindMap();
    void setSymTbl(string first, double second);
    void setSymTbl3(map<string,double> x);
    void setbindMap(string first,string second);
    int getWriteSocket(){
            return this->writeSocket;
    }

    void setSocket(int so){
            this->writeSocket = so;
    }


};


#endif //PROJECT_PART1_DATA_H
