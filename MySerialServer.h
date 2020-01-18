//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public server_side::Server {
public:
    MySerialServer();
    void open(int port, ClientHandler *c) override;
    static void start(int port, ClientHandler *c);
    void close() override;
};


#endif //MILESTONE_2_MYSERIALSERVER_H
