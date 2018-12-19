//
// Created by gad on 12/19/18.
//

#include "OpenServerCommand.h"
#include "Expression.h"


void OpenServerCommand::doCommand() {
    //transform first to expression
    //transform second to expression
    //fixness check

    Expression* ExFirst = shutingYard(this->first);
    Expression* ExSecond = shutingYard(this->second);
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