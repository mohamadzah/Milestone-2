//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H

#include "Server.h"
/**
 * MySerialServer
 */
class MySerialServer : public server_side::Server {
public:
    MySerialServer();
    //open server on given port
    void open(int port, ClientHandler *c) override;
    //start the server
    static void start(int newSC, ClientHandler *c);
    //close
    void close() override;
};


#endif //MILESTONE_2_MYSERIALSERVER_H
