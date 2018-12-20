//
// Created by gad on 12/19/18.
//

#include <iostream>
#include "connectCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "Data.h"
#include "DataWriterServer.h"

struct MyParams {
    int port;
    string address;
    Data *data;
};

double connectCommand::doCommand() {

    ShuntingYard a;
    vector<string> postfix;

    postfix = a.infixToPostfix(this->port);
    Expression *ExFirst = a.stringToExpression(postfix);
    map<string, double> SymTbl;
//    SymTbl = data->getSymTbl();

    int port2 = (int) ExFirst->calculate(SymTbl);
    cout << port2 << endl;

    cout << address << endl;
    //fixness check for address

    struct MyParams *params = new MyParams();
    params->port = port2;
    params->address = this->address;
    params->data = this->data;

    pthread_t trid;
    pthread_create(&trid, nullptr, DataWriterServer::client_sock, params);


    return 2;
}

int connectCommand::parameterAmount() {
    return 2;
}

void connectCommand::setParameters(list<string> ls) {
    list<string>::iterator it;
    int i = 0;
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (i == 1) {
            this->address = *it;
        }
        if (i == 2) {
            this->port = *it;
        }
        if (i > 2) {
            cout << "error" << endl;
            throw 0;
        }
        i = i + 1;
    }
}