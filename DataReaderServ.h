//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_DATAREADERSERV_H
#define PROJECT_PART1_DATAREADERSERV_H


class DataReaderServ {
    int port;
    int Hz;
public:
    DataReaderServ (int port, int Hz){
        this->port = port;
        this->Hz = Hz;
    };
    void server_Sock();

};


#endif //PROJECT_PART1_DATAREADERSERV_H
