//
// Created by gad on 12/19/18.
//

#include "OpenServerCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"

#include "DataReaderServ.h"


double OpenServerCommand::doCommand() {

    ShuntingYard a;
    vector<string> postfix;
    postfix = a.infixToPostfix(this->first);
    Expression* ExFirst = a.stringToExpression(postfix);


    postfix = a.infixToPostfix(this->second);
    Expression* ExSecond = a.stringToExpression(postfix);

    map<string,double> SymTbl;
    int port = (int)ExFirst->calculate(SymTbl);
    cout<<port<<endl;

    int Hz = (int)ExSecond->calculate(SymTbl);
    cout<<Hz<<endl;

    DataReaderServ* drs = new DataReaderServ(port,Hz);
    drs->server_Sock();

    return 2;

}

int OpenServerCommand::parameterAmount(){
    return 2;
}

void OpenServerCommand::setParameters(list<string> ls) {
    list<string>::iterator it;
    int i =0;
    for (it = ls.begin();it != ls.end();++it) {
        if (i==1){
            this->first=*it;
        }
        if (i==2){
            this->second=*it;
        }
        if (i>2){
            cout<<"error"<<endl;
            throw 0;
        }
        i = i + 1;
    }
}