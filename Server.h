//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_SERVER_H
#define MILESTONE_2_SERVER_H

#include "ClientHandler.h"

/**
 * The Server Interface.
 *
 */

namespace server_side {

    class Server {
    public:
        virtual void open(int port, ClientHandler *c) = 0;
        virtual void close() = 0;
    };

}


#endif //MILESTONE_2_SERVER_H
