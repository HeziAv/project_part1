//
// Created by gad on 12/19/18.
//

#include "OpenServerCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "DataReaderServ.h"
#include "Data.h"
#include <iostream>
#include <pthread.h>
#include <stdio.h>

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
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

struct MyParams {
    int port;
    Data *data;
};
//mutex mtx;

double OpenServerCommand::doCommand(Data *data) {

    ShuntingYard a;
    vector<string> postfix;
    postfix = a.infixToPostfix(this->first);
    Expression *ExFirst = a.stringToExpression(postfix);
    postfix = a.infixToPostfix(this->second);
    Expression *ExSecond = a.stringToExpression(postfix);


    int port = (int) ExFirst->calculate(data);
    cout << port << endl;
    int Hz = (int) ExSecond->calculate(data);
    cout << Hz << endl;
    data->setHz(Hz);

//    struct MyParams* params = new MyParams();
//    params->port=port;

//    params->data = data;


//    struct MyParams *params = (struct MyParams *) arg;

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
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
    portno = port;

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

    data->setReadSocket(newsockfd);


    thread serverThread(server_Sock, newsockfd, data);
    serverThread.detach();
//    serverThread.join();

    return 2;
}

int OpenServerCommand::parameterAmount() {
    return 2;
}

void OpenServerCommand::setParameters(list<string> ls,Data* data1) {
    list<string>::iterator it;
    int i = 0;
    for (it = ls.begin(); it != ls.end(); ++it) {
        if (i == 1) {
            this->first = *it;
        }
        if (i == 2) {
            this->second = *it;
        }
        if (i > 2) {
            cout << "error" << endl;
            throw 0;
        }
        i = i + 1;
    }

}


int OpenServerCommand::getSocketId() {
    return this->SocketId;
}

void OpenServerCommand::setSocketId(int var) {
    this->SocketId = var;
}

void *OpenServerCommand::server_Sock(int sockfd, Data *data) {
    char buffer[256];
    int n;

//    lock_guard<mutex> lock(data->getMutex());

    string temp;
    char reminder[256];
    bzero(reminder, 256);
    int newsockfd = sockfd;
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
        temp = "";
        int countR = 0;
        while (strlen(reminder) != 0) {
            countR++;
        }
        // create new buf = reminder + buffer
        char buf[256];
        for (int l = 0; l < countR; ++l) {
            buf[l] = reminder[l];
        }
        for (countR; countR < 256; ++countR) {
            buf[countR] = buffer[countR];
        }

        // convert buf to list of doubles and keep the reminder
        bzero(reminder, 256);
        for (long i = 0; i < 256; i++) {
            if (buf[i] == 10) {
                i++;
                double value = atof(temp.c_str());
                ls.push_back(value);
                temp = "";
                int k = 0;
                // keep reminder
                for (i; i < 256; i++) {
                    reminder[k] = buf[i];
                    k++;
                }
                break;
            } else if (buf[i] == ',') {
                double value = atof(temp.c_str());
                ls.push_back(value);
                temp = "";
            } else {
                temp.push_back(buf[i]);
            }
        }
        string key = "";
        int j = 0;
        // put in the map the keys and their values or change exits keys
        list<double>::iterator it;
        for (it = ls.begin(); it != ls.end(); ++it) {
            switch (j) {
                case 0:
                    key = "/instrumentation/airspeed-indicator/indicated-speed-kt";
                    break;
                case 1 :
                    key = "/instrumentation/altimeter/indicated-altitude-ft";
                    break;
                case 2 :
                    key = "/instrumentation/altimeter/pressure-alt-ft";
                    break;
                case 3 :
                    key = "/instrumentation/attitude-indicator/indicated-pitch-deg";
                    break;
                case 4 :
                    key = "/instrumentation/attitude-indicator/indicated-roll-deg";
                    break;
                case 5 :
                    key = "/instrumentation/attitude-indicator/internal-pitch-deg";
                    break;
                case 6 :
                    key = "/instrumentation/attitude-indicator/internal-roll-deg";
                    break;
                case 7 :
                    key = "/instrumentation/encoder/indicated-altitude-ft";
                    break;
                case 8 :
                    key = "/instrumentation/encoder/pressure-alt-ft";
                    break;
                case 9 :
                    key = "/instrumentation/gps/indicated-altitude-ft";
                    break;
                case 10 :
                    key = "/instrumentation/gps/indicated-ground-speed-kt";
                    break;
                case 11 :
                    key = "/instrumentation/gps/indicated-vertical-speed";
                    break;
                case 12 :
                    key = "/instrumentation/heading-indicator/indicated-heading-deg";
                    break;
                case 13 :
                    key = "/instrumentation/magnetic-compass/indicated-heading-deg";
                    break;
                case 14:
                    key = "/instrumentation/slip-skid-ball/indicated-slip-skid";
                    break;
                case 15 :
                    key = "/instrumentation/turn-indicator/indicated-turn-rate";
                    break;
                case 16 :
                    key = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
                    break;
                case 17 :
                    key = "/controls/flight/aileron";
                    break;
                case 18 :
                    key = "/controls/flight/elevator";
                    break;
                case 19 :
                    key = "/controls/flight/rudder";
                    break;
                case 20 :
                    key = "/controls/flight/flaps";
                    break;
                case 21 :
                    key = "/controls/engines/engine/throttle";
                    break;
                case 22 :
                    key = "/engines/engine/rpm";
                    break;
                default:
                    cout << "gaddi" << endl;
                    break;
            }
            data->setSymTbl(key, *it);
            ++j;
        }

//        printf("Here is the message: %s\n", buf);
        bzero(buf, 256);

/* Write a response to the client */
        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        int Hz = (data->getHz());
        usleep(1 / Hz);

    }
}
