//
// Created by gad on 12/19/18.
//

#include "DataReaderServ.h"
#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <string>
#include <regex>
#include <list>

//gad
using namespace std;
struct MyParams {
    int port;
    Data data;
};

void* DataReaderServ::server_Sock(void* arg) {

    struct MyParams *params = (struct MyParams *) arg;

    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

/* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }


/* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = params->port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

/* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

/* Now start listening for the clients, here process will
   * go in sleep mode and will wait for the incoming connection
*/

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

/* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    std::cout << "gad" << std::endl;
    while (true) {
/* If connection is established then start communicating */
        bzero(buffer, 256);
        //sleep for this->Hz
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        // convert the buffer to list of doubles
        list<double> ls;
        string temp;
        for(long i = 0;i<1024;i++){
            while(buffer[i] != ','){
                temp.push_back(buffer[i]);
                i++;
            }
            double value = atof(temp.c_str());
            ls.push_back(value);
            temp = "";
        }


       printf("Here is the message: %s\n", buffer);


/* Write a response to the client */
        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }


}

int DataReaderServ::getSocketId() {
    return this->SocketId;
}

void DataReaderServ::setSocketId(int var) {
    this->SocketId = var;
}