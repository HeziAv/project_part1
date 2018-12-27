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
#include <iostream>
#include <strings.h>
#include <cstring>
#include <unistd.h>


class Data {
    map<string, Variable *> newTbl;
    string global;
    int sockfd;
    int servSocket;
public:
    Data() = default;

    string getGlobal() const {
        return global;
    }

    void setSockfd(int s) {
        this->sockfd = s;
    }

    void setGlobal(string s) {

//        if (global==""){
//            global=s;
//        }else{
//            cout<<"error : multipling globals to server"<<endl;
//            throw 0;
//        }
//    }

        char buffer[256];
        for (int i = 0; i < 256; i++) {
            buffer[i] = '\000';
        }

//    while (true) {

//        if (data->getGlobal() != "") {

        int n;


        /* Now ask for a message from the user, this message
           * will be read by server
        */
//            cout << "Please enter the message: " << endl;


        bzero(buffer, 256);

//            fgets(buffer, 255, stdin);

//            string s = global;
        for (int i = 0; i < s.length(); i++) {
            buffer[i] = s[i];
        }

        /* Send message to the server */

        n = write(sockfd, buffer, strlen(buffer));


        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        /* Now read server response */
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

//            cout << buffer << endl;

//        printf("%s\n", buffer);

//            data->setGlobal("");
//        }
//    }
    }


    void addToNewTable(const string &first, Variable *second) {
        newTbl[first] = second;
    }

    Variable *operator[](const string &key) {
        if (newTbl.count(key) == 0) throw std::invalid_argument("no such key");
        return newTbl[key];
    }

    map<string, Variable *> getNewTbl() {
        return this->newTbl;
    }

    Variable *operator[](const string &key) const {
        return newTbl.at(key);
    }

    bool has_key(const string &key) const {
        return newTbl.count(key) == 1;
    }

    string hasPath(string path) {
        string key = "";

        map<string, Variable *>::iterator it;

        for (it = this->newTbl.begin(); it != this->newTbl.end(); it++) {
            if (it->second->getIsBound()) {
                if (it->second->getPath() == path) {
                    return it->first;
                }
            }
        }
        return key;
    }

    int getSokcetServer() {
        return servSocket;
    }

    void setSokcetServer(int d) {
        this->servSocket = d;
    }

    int getSocketConnect() {
        return this->sockfd;
    }


};


#endif //PROJECT_PART1_DATA_H
