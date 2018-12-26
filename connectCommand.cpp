//
// Created by gad on 12/19/18.
//

#include <iostream>
#include "connectCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "Data.h"
#include "DataWriterServer.h"
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


struct MyParams {
    int port;
    string address;
    Data *data;
};

double connectCommand::doCommand(Data *data4) {

    ShuntingYard a;
    vector<string> postfix;

    postfix = a.infixToPostfix(this->port);
    Expression *ExFirst = a.stringToExpression(postfix);

    int port2 = (int) ExFirst->calculate(data4);
    cout << port2 << endl;

    cout << address << endl;
    //fixness check for address

    struct MyParams *params = new MyParams();
    params->port = port2;
    params->address = this->address;
    params->data = data4;


    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    portno = params->port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    params->data->setSocket(sockfd);
    cout << sockfd << endl;
//set socket id to data
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(params->address.c_str());

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


    thread serverThread(client_sock, sockfd, data4);
    serverThread.detach();
//serverThread.join();

    return 2;
}

int connectCommand::parameterAmount() {
    return 2;
}

void connectCommand::setParameters(list<string> ls,Data* data1) {
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

void *connectCommand::client_sock(int sockfd, Data *data) {
    char buffer[256];
    for (int i = 0; i < 256; i++) {
        buffer[i] = '\000';
    }

    while (true) {

    if (data->getGlobal() != "") {

        int n;


        /* Now ask for a message from the user, this message
           * will be read by server
        */

        cout << "Please enter the message: " << endl;


        bzero(buffer, 256);

        fgets(buffer, 255, stdin);

        string s = data->getGlobal();
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

        cout << buffer << endl;

        printf("%s\n", buffer);

        data->setGlobal("");
    }
    }
}
