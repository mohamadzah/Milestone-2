#include <iostream>
#include "MySerialServer.h"
#include "StringReverser.h"
#include "Solver.h"
#include "ClientHandler.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "algorithm"
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "SolveProblem.h"
#include "AlgorithmSearchable.h"
#include "BestFirstSearch.h"
#include "AlgorithmSolver.h"
#include "DFS.h"
#include "BFS.h"
#include "Astar.h"
using namespace std;

namespace boot {
    class Main {
    public:
        int main(int argc, char* argv[]) {
            //read the port.
            int port = std::stoi(argv[1]);
            //create client hander.
            //Winning algorithm Astar
            auto algorithm = new Astar<Cell>();
            //Choosing the solver.
            Solver<Searchable<Cell> * , string> * solver = new AlgorithmSolver(algorithm);
            auto * cacheManager = new FileCacheManager();
            ClientHandler * clientHandler = new MyClientHandler(solver, cacheManager);
            auto * server = new MyParallelServer();
            //open the server on port given.
            server->open(port, clientHandler);
            return 0;
        }
    };
}

using namespace boot;

int main(int argc, char* argv[]) {
    Main m;
    m.main(argc, argv);
    return 0;
}
