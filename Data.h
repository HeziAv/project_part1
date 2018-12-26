//
// Created by hezi on 12/19/18.
//

#ifndef PROJECT_PART1_DATA_H
#define PROJECT_PART1_DATA_H

#include "Data.h"
using namespace std;
#include <map>
#include <mutex>


class Data {
    map<string,double> SymTbl;
    map<string,string> bindMap;
    int readSocket;
    int writeSocket;
    int Hz;
    string buffer;
    int flag = 0;
//    mutex mtx;


public:
    Data(){
        map<string,double> SymTbl1 = {{"x",0}, {"heading", 0}, {"roll", 0}, {"pitch", 0}, {"pitch", 0}, {"rudder", 0}, {"elevator", 0}, {"alt", 0}};
        this->SymTbl = SymTbl1;
        map<string,string> bindMap = {{"x","0"}};
        this->bindMap = bindMap;
        this->readSocket=0;
        this->writeSocket=0;
        this->buffer="";




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
    void setReadSocket(int so){
        this->readSocket = so;
    }
    int getReadSocket(){
        return this->readSocket;
    }

    void setHz(int so){
        this->Hz = so;
    }
    int getHz(){
        return this->Hz;
    }

    void setGlobal(string so){
        this->buffer = so;
    }
    string getGlobal(){
        return this->buffer;;
    }
    void setFlag(int f){
        flag = f;
    }
    int getFlag(){
        return flag;
    }

//    mutex getMutex(){
//        return this->mtx;;
//    }






};


#endif //PROJECT_PART1_DATA_H
