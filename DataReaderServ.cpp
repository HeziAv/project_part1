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
    Data* data;
};

void* DataReaderServ::server_Sock(void* arg) {

    struct MyParams *params = (struct MyParams *) arg;

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

    string temp;
    char reminder[256];
    bzero(reminder, 256);


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
        while (strlen(reminder) != 0){
            countR++;
        }
        // create new buf = reminder + buffer
        char buf[256];
        for (int l = 0; l < countR ; ++l) {
            buf[l] = reminder[l];
        }
        for (countR; countR < 256 ; ++countR) {
            buf[countR] = buffer[countR];
        }

        // convert buf to list of doubles and keep the reminder
        bzero(reminder,256);
        for(long i = 0;i<256;i++) {
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
        list<double >::iterator it;
        for (it = ls.begin(); it != ls.end(); ++it) {
            switch (j) {
                case 0:
                    key = "engine_rpm";
                    break;
                case 1 :
                    key = "engine_throttle";
                    break;
                case 2 :
                    key = "flight_flaps";
                    break;
                case 3 :
                    key = "flight_rudder";
                    break;
                case 4 :
                    key = "flight_elevator";
                    break;
                case 5 :
                    key = "flight_aileron";
                    break;
                case 6 :
                    key = "vertical-speed-indicator_indicated-speed-fpm";
                    break;
                case 7 :
                    key = "turn-indicator_indicated-turn-rate";
                    break;
                case 8 :
                    key = "slip-skid-ball_indicated-slip-skid";
                    break;
                case 9 :
                    key = "magnetic-compass_indicated-heading-deg";
                    break;
                case 10 :
                    key = "indicated-heading-deg";
                    break;
                case 11 :
                    key = "gps_indicated-vertical-speed";
                    break;
                case 12 :
                    key = "gps_indicated-ground-speed-kt";
                    break;
                case 13 :
                    key = "gps_indicated-altitude-ft";
                    break;
                case 14:
                    key = "encoder_indicated-altitude-ft";
                    break;
                case 15 :
                    key = "encoder_pressure-alt-ft";
                    break;
                case 16 :
                    key = "attitude-indicator_internal-roll-deg";
                    break;
                case 17 :
                    key = "attitude-indicator_internal-pitch-deg";
                    break;
                case 18 :
                    key = "attitude-indicator_indicated-roll-deg";
                    break;
                case 19 :
                    key = "attitude-indicator_indicated-pitch-deg";
                    break;
                case 20 :
                    key = "altimeter_pressure-alt-ft";
                    break;
                case 21 :
                    key = "altimeter_indicated-altitude-ft";
                    break;
                case 22 :
                    key = "airspeed-indicator_indicated-speed-kt";
                    break;
                default:
                    cout << "gaddi" << endl;
                    break;
            }
            params->data->setSymTbl(key,*it);
            ++j;
        }

//        printf("Here is the message: %s\n", buf);
        bzero(buf,256);

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