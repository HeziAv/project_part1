//
// Created by gad on 12/19/18.
//

#ifndef PROJECT_PART1_DATAREADERSERV_H
#define PROJECT_PART1_DATAREADERSERV_H


class DataReaderServ {
    int port;
    int Hz;
    int SocketId;
public:
    DataReaderServ (int port, int Hz){
        this->port = port;
        this->Hz = Hz;
    }

    static void* server_Sock(void* arg);
    int getSocketId();
    void setSocketId(int var);

};


#endif //PROJECT_PART1_DATAREADERSERV_H
