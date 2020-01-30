//
// Created by zahalka on 13/01/2020.
//

#include "MyTestClientHandler.h"
/**
 * Constructor.
 * @param _solver
 * @param _fm
 */
MyTestClientHandler::MyTestClientHandler(Solver<std::string, std::string> *_solver, FileCacheManager *_fm) {
    this->solver = _solver;
    this->fm = _fm;
}

void MyTestClientHandler::handleClient(int newSC) {
    //here using the socket, we will read the message, call the string solver and solve it.
    //then send the message solved back to the client.
    while (true) {
        char buffer[1024] = {0};
        int valread = read(newSC, buffer, 1024);
        if (valread < 0) {
            cerr << "Error reading from the client" << endl;
            exit(1);
        }
        //check whether problem has a solution
        if (this->fm->solExists(buffer)) {
            string solution = this->fm->get(buffer);
            valread = write(newSC, solution.c_str(), strlen(solution.c_str()));
        } else {
            //if we do not have a solution, we will create one and add it into the cache
            string solution = solver->solve(buffer);
            fm->insert(buffer, solution);
            valread = write(newSC, solution.c_str(), strlen(solution.c_str()));
        }
    }
}
