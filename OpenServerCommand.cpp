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


    thread serverThread(server_Sock, newsockfd, data);
    serverThread.detach();
//    serverThread.join();

    return 2;
}

int OpenServerCommand::parameterAmount() {
    return 2;
}

void OpenServerCommand::setParameters(list<string> ls, Data *data1) {
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

pair<string, string> read_until(int sockfd, string sep, string remainder) {
    char buffer[256];
    while (remainder.find(sep) == string::npos) {
        ssize_t bytes_read = (read(sockfd, buffer, 255));
        if (bytes_read < 0) {
            perror("Invalid socket read");
            exit(1);
        }
        buffer[bytes_read] = 0;
        remainder += string(buffer);
    }

    unsigned long pos = remainder.find(sep);
    pair<string, string> output;
    output.first = remainder.substr(0, pos);
    output.second = remainder.substr(pos + 1);

    return output;
}

void *OpenServerCommand::server_Sock(int sockfd, Data *data) {
    char buffer[256];
    string remainder;
    string buff;

    /* If connection is established then start communicating */
    int fu_k = 0;
    while (true) {
        if (fu_k) exit(1);
        auto out = read_until(sockfd, "\n", remainder);
        remainder = out.second;
        buff = out.first;


        list<double> info;
        try {
            info = split(buff);
        } catch (std::exception &e) {
            int i = 0;
        }
//        cout << info.size() << endl;

        string key = "";
//            int j = 0;
        int j = 0;
        for (double &it : info) {
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
                    key = "/controls/engines/current-engine/throttle";
                    break;
                case 22 :
                    key = "/engines/engine/rpm";
                    break;
                default:
                    cout << "gaddi" << endl;
                    break;
            }
//            if (j == 22) {
//                cout << it << endl;
//            }

            j++;


            if (data->has_key(key)) {
                (*data)[key]->setVal(it);
            } else if (data->hasPath(key)!=""){
                (*data)[(data->hasPath(key))]->setVal(it);
            }
            else {
                auto *variable = new Variable;
                variable->setVal(it);
                variable->setIsBound(true);
                variable->setPath(key);
                data->addToNewTable(key, variable);
            }

        }
    }
}

list<double> OpenServerCommand::split(string buffer) {
    list<double> ret;

    size_t pos = 0;
    string delimiter = ",";
    size_t begin = 0;

    while ((pos = buffer.find(delimiter, begin)) != string::npos) {
        string temp = buffer.substr(begin, pos);
        ret.push_back(stod(temp));
        begin = pos + delimiter.length();
    }

    ret.push_back(stod(buffer.substr(begin)));
    return ret;
}

