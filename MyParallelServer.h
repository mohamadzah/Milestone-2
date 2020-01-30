//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H

#include "Server.h"
#include <vector>

class MyParallelServer : public server_side::Server {
    //Fields of server
    vector<thread> threadVector;
    int serverSocket;
    vector<int> sockets;
    //new struct to deep copy clienthandler
    struct threadArgument {
        int newSC;
        ClientHandler * c;
    };
    struct threadArgument * argument = new threadArgument();
public:
    //Constructor
    MyParallelServer();
    //Open server on port
    void open(int port, ClientHandler *c) override;
    //close sockets
    void close() override;
    //destructor.
    ~MyParallelServer();
    //start
    static void * start(void *argument);
    //join the threads.
    void joinT();
};

#endif //MILESTONE_2_MYPARALLELSERVER_H
