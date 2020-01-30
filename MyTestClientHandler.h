//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_MYTESTCLIENTHANDLER_H
#define MILESTONE_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Server.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include <string>
/**
 * first client tester , test the conversation between client and server
 *
 */
class MyTestClientHandler : public ClientHandler {
private:
    Solver<std::string, std::string> *solver;
    FileCacheManager *fm;
public:
    MyTestClientHandler(Solver<std::string, std::string> *solver, FileCacheManager *fm);
    void handleClient(int newSC) override;
};

#endif //MILESTONE_2_MYTESTCLIENTHANDLER_H
