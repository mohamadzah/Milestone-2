//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_CLIENTHANDLER_H
#define MILESTONE_2_CLIENTHANDLER_H
/**
 * Interface
 */
class ClientHandler {
public:
    //send the socket that the current client connected with, and read using it.
    virtual void handleClient(int newSC) = 0;
    virtual ClientHandler *Clone() = 0;
    virtual ~ClientHandler() = default;
};

#endif //MILESTONE_2_CLIENTHANDLER_H
