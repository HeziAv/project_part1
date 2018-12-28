//
// Created by gad on 12/19/18.
//

#include <iostream>
#include "connectCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "Data.h"
#include <string.h>
#include <iostream>

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>


void connectCommand::doCommand(Data *data4) {

    ShuntingYard a;
    vector<string> postfix;

    postfix = a.infixToPostfix(this->port);
    Expression *ExFirst = a.stringToExpression(postfix);

    int port2 = (int) ExFirst->calculate(data4);
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = port2;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    data4->setSockfd(sockfd);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }


    server = gethostbyname(this->address.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

data4->setSockfd(sockfd);
//    thread serverThread(client_sock, sockfd, data4);
//    serverThread.detach();
//serverThread.join();

}



void connectCommand::setParameters(list<string> ls, Data *data1) {
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



