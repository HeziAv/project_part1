//
// Created by gad on 12/19/18.
//

#include <iostream>
#include "connectCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"

#include "DataWriterServer.h"


double connectCommand::doCommand() {

    ShuntingYard a;
    vector<string> postfix;

    postfix = a.infixToPostfix(this->port);
    Expression* ExFirst = a.stringToExpression(postfix);


    map<string,double> SymTbl;
    int port2 = (int)ExFirst->calculate(SymTbl);
    cout<<port2<<endl;

    //fixness check for address

    //int port2 = 5402;


    DataWriterServer* dws = new DataWriterServer(port2,address);
    dws->client_sock();
    return 2;
}

int connectCommand::parameterAmount(){
    return 2;
}

void connectCommand::setParameters(list<string> ls) {
    list<string>::iterator it;
    int i =0;
    for (it = ls.begin();it != ls.end();++it) {
        if (i==1){
            this->address=*it;
        }
        if (i==2){
            this->port=*it;
        }
        if (i>2){
            cout<<"error"<<endl;
            throw 0;
        }
        i = i + 1;
    }
}