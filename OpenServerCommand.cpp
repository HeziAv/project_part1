//
// Created by gad on 12/19/18.
//

#include "OpenServerCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"


void OpenServerCommand::doCommand() {
    //transform first to expression
    //transform second to expression
    //fixness check
    ShuntingYard a;
    vector<string> postfix;
    postfix = a.infixToPostfix(this->first);
    Expression* ExFirst = a.stringToExpression(postfix);
    postfix = a.infixToPostfix(this->second);
    Expression* ExSecond = a.stringToExpression(postfix);
    new dataReaderServer drs = new dataReaderServer(ExFirst.calculate();,ExSecond.calculate(); )

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
        i=i+1;
        if (i>2){
            cout<<"error"<<endl;
            throw 0;
        }
    }



    this
}