//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H

#include "Server.h"
#include <vector>

class MyParallelServer : public server_side::Server {
    vector<thread> threadVector;
public:
    MyParallelServer();
    void open(int port, ClientHandler *c) override;
    static void start(int port, ClientHandler *c);
    void close() override;
};

#endif //MILESTONE_2_MYPARALLELSERVER_H
