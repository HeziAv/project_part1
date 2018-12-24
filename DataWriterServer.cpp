//
// Created by gad on 12/19/18.
//

#include "DataWriterServer.h"
#include "Data.h"


#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

#include <string.h>
#include "string.h"

struct MyParams {
    int port;
    string address;
    Data *data;
};


void *DataWriterServer::client_sock(void *arg) {
    struct MyParams *params = (struct MyParams *) arg;
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

//    /* Now ask for a message from the user, this message
//       * will be read by server
//    */
//
//
//        cout << "Please enter the message: " << endl;
//
//
//        bzero(buffer, 256);
//
//        fgets(buffer, 255, stdin);
//
//        string s = "set controls/flight/rudder 1\r\n";
//        for (int i = 0; i < s.length(); i++) {
//            buffer[i] = s[i];
//        }
//
//
//
//
//        /* Send message to the server */
//
//        n = write(sockfd, buffer, strlen(buffer));
//
//
//
//        if (n < 0) {
//            perror("ERROR writing to socket");
//            exit(1);
//        }
//
//        /* Now read server response */
//        bzero(buffer, 256);
//        n = read(sockfd, buffer, 255);
//
//        if (n < 0) {
//            perror("ERROR reading from socket");
//            exit(1);
//        }
//
//        cout << buffer << endl;
//
//        printf("%s\n", buffer);

    }
