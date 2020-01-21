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

template <class Problem, class Solution>
class MyClientHandler : public ClientHandler {
    Solver<Problem, Solution> *solver;
    CacheManager<Problem, Solution> *fileManager;
public:
    MyClientHandler(Solver<Problem, Solution> *solver, CacheManager<Problem, Solution> *fileManager);
    void handleClient(int newSC) override;
    vector<vector<string>> readSolution(int newSC);
    vector<string> removeComma(char buffer[], int s);
};

#endif //MILESTONE_2_MYCLIENTHANDLER_H
