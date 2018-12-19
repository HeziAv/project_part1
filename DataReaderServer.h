//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_DATAREADERSERVER_H
#define PROJECT_PART1_DATAREADERSERVER_H


class DataReaderServer {

    int port;
    int Hz;
public:
    DataReaderServer (int port, int Hz);

    void server_sock();
    void client_sock(int argc, char *argv[]);



};


#endif //PROJECT_PART1_DATAREADERSERVER_H
