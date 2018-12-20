//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_DATAWRITERSERVER_H
#define PROJECT_PART1_DATAWRITERSERVER_H

#include <string.h>
#include <iostream>
using namespace std;

class DataWriterServer {
int port;
string address;

public:

    DataWriterServer (int port1, string address1) {
        this->port = port1;
        this->address = address1;
    }

    static void* client_sock(void* arg);


};


#endif //PROJECT_PART1_DATAWRITERSERVER_H
