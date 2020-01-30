//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_SERVER_H
#define MILESTONE_2_SERVER_H

#include "ClientHandler.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <cmath>
#include <cstring>
#include <sstream>

/**
 * The Server Interface.
 *
 */

using namespace std;

// global bool to close the server when we should.

namespace server_side {

    class Server {
    protected:
        bool closeServer{};
    public:
        //open the server on given port
        virtual void open(int port, ClientHandler *c) = 0;
        //close the sockets.
        virtual void close() = 0;
        virtual ~Server() = default;
    };

}


#endif //MILESTONE_2_SERVER_H
