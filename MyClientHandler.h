//
// Created by zahalka on 15/01/2020.
//

#ifndef MILESTONE_2_MYCLIENTHANDLER_H
#define MILESTONE_2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Server.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include <string>
#include <vector>
#include "Cell.h"
#include "Searcher.h"

class MyClientHandler : public ClientHandler {
    //Fields
    string problem;
    Solver<Searchable<Cell> *, string> *solver;
    CacheManager<string, string> *fileManager;
public:
    //Constructor
    MyClientHandler(Solver<Searchable<Cell> *, string> *solver, CacheManager<string, string> *fileManager);
    //handle client function.
    void handleClient(int newSC) override;
    //read from client.
    vector<vector<string>> readSolution(int newSC);
    //remove commas from client input.
    vector<string> removeComma(char buffer[], int s);
    //clone the client handler.
    ClientHandler *Clone() override;
};

#endif //MILESTONE_2_MYCLIENTHANDLER_H
