//
// Created by gad on 12/20/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

#include <string.h>
#include "string.h"
#include <cstring>
#include "EqualCommand.h"
#include "ShuntingYard.h"
//check






struct MyParams {
    int port;
    Data *data;
};


double EqualCommand::doCommand(Data *data2) {
    struct sockaddr_in serv_addr;

//    setParameters(this->ls);
    // check if there is bind
    if (this->isAbind == true) {
        map<string, string> bindMap;
        bindMap = data2->getbindMap();
        data2->setbindMap(this->first, this->second); // found

    } else {
        map<string, double> symMap;

//        symMap = this->data->getSymTbl();
        ShuntingYard a;
        vector<string> postfix;
        postfix = a.infixToPostfix(this->second);
        Expression *ExFirst = a.stringToExpression(postfix);

        double sec = ExFirst->calculate(data2);

        ///////// gaddddddddd
        if (symMap.count(this->first) > 0) {
            data2->setSymTbl(this->first, sec);
        } else {
            string buffer = "set ";
            string temp = data2->getbindMap().find(first)->second;
            buffer = buffer + temp;
            temp = second;
            buffer = buffer + " " + temp;
            buffer = buffer + " \r\n";
            char buffer1[256];
            for (int i = 0; i < 256; i++) {
                if (buffer[i] != '\000') {
                    buffer1[i] = buffer[i];
                } else {
                    buffer1[i] = '\000';
                }
            }

            data2->setGlobal(buffer);

//            /* Send message to the server */
//            int n;
//            int sockfd = data2->getWriteSocket();
//
//            char buffer123[256];
//
//            bzero(buffer123, 256);
//
//            fgets(buffer123, 255, stdin);

//            string s = "set controls/flight/rudder 1\r\n";

//            for (int i = 0; i < s.length(); i++) {
//                buffer123[i] = s[i];
//            }
//
//
//
//
//        /* Send message to the server */
//
//            n = write(sockfd, buffer123, strlen(buffer123));






//if(::send(sockfd,buffer.c_str(), buffer.length(),0)<0){
//    perror("Error writing gad");
//}

//            n = (write(sockfd, buffer1, strlen(buffer1)));

//            if (n < 0) {
//                perror("ERROR writing to socket");
//                exit(1);
//            }


            data2->setSymTbl(this->first, sec);
        }
    }
    return 3;
}


int EqualCommand::parameterAmount() {
    return 2;
}

void EqualCommand::setParameters(list<string> ls,Data* data) {
    list<string>::iterator it;
    this->first = "";
    this->second = "";
    int i = 0;
    if (ls.size() > 5 || ls.size() < 3) {
        cout << "error" << endl;
        throw 0;
    }
    int flag = 0;
    // take the variable before =
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (*it == "var") {
            this->newVar = true;
            flag = 1;
            continue;
        }
        this->first = *it;
        i = 1;
        break;
    }
    if(flag == 0)
        this->newVar = false;
    // take the variable after =
    for (it; it != ls.end(); ++it) {
        if (*it == "=") {
            ++it;
            if (*it == "bind") {
                this->isAbind = true;
                ++it;
            } else {
                this->isAbind = false;
            }
            this->second = *it;
            i = 2;
            break;
        }
    }

    if (i != 2 || this->first == "var") {
        cout << "error" << endl;
        throw 0;
    }
}
