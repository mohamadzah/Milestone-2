//
// Created by zahalka on 15/01/2020.
//

#include "MyClientHandler.h"
#include "AlgorithmSearchable.h"
#include "mutex"
/**
 * handle the client connected to a given socket.
 * @param newSC the socket.
 */
void MyClientHandler::handleClient(int newSC) {
    vector<State<Cell> *> matrix;
    //get the message from the client.
    vector<vector<string>> values = readSolution(newSC);

    //create the states for all cells.
    auto size = values.size() - 2;
    for (int i = 0; i < size; i++) {
        //set values.
        for (int k = 0; k < values[i].size(); k++) {
            auto it = values[i];
            State<Cell> * state;
            state = new State<Cell>(std::stod(it[k]), Cell(k, i));
            matrix.push_back(state);
        }
    }

    State<Cell> *goalState = nullptr;
    State<Cell> *initialState = nullptr;
    //find the intial state.
    int rowInitial = stoi((values[size]).at(0)), columnInitial = stoi((values[size]).at(0));
    for (auto & i : matrix) {
        if ((i->getState().getRow() == rowInitial) && (i->getState().getColumn() == columnInitial)) {
            initialState = i;
            break;
        }
    }
    //find the goal state.
    int rowGoal = stoi((values[size+1]).at(0)), columnGoal = stoi((values[size+1]).at(0));
    for (auto & i : matrix) {
        int tr = i->getState().getRow();
        int meow = i->getState().getColumn();
        if ((tr == rowGoal) && (meow == columnGoal)) {
            goalState = i;
            break;
        }
    }

    //now we create a searchable.
    Searchable<Cell> *searchable = new AlgorithmSearchable(initialState, goalState, matrix);
    //try and find the solution if he already created it
    if (this->fileManager->solExists(this->problem)) {
        //if we have the solution, we get it.
        string solution = fileManager->get(problem);
        ssize_t msg = write(newSC, solution.c_str(), solution.length());
        if (msg < 0) {
            cerr << "error" << endl;
            exit(1);
        }
    } else {
        //if there isnt a solution from previous runs, we solve it.
        string sol = this->solver->solve(searchable);
        //write it to a file.
        fileManager->insert(this->problem, sol);
        ssize_t msg = write(newSC, sol.c_str(), sol.length());
        if (msg < 0) {
            cerr << "error" << endl;
            exit(1);
        }
    }
    problem.clear();
}
/**
 * Constructor.
 *
 * @param solver
 * @param fileManager
 */
MyClientHandler::MyClientHandler(Solver<Searchable<Cell> *, string> *solver, CacheManager<string, string> *fileManager) {
    this->solver = solver;
    this->fileManager = fileManager;
}
/**
 * Reading from the client.
 * @param newSC
 * @return vector that has the values.
 */
vector<vector<string>> MyClientHandler::readSolution(int newSC) {
    char buffer[1024] = {0};
    vector<vector<string>> values;
    vector<string> line;
    while (true) {
        bzero(buffer,1024);
        int valread = read(newSC, buffer, 1024);
        if (strcmp(buffer, "end\n") == 0 || (strcmp(buffer, "\0") == 0)) {
            break;
        }
        if (valread < 0) {
            cerr << "Error reading from the client" << endl;
            exit(1);
        }
        if (strcmp(buffer, "end\n") != 0 && (strcmp(buffer, "\0") != 0)) {
            line = removeComma(buffer, 1024);
            problem += buffer;
            problem.pop_back();
            values.push_back(line);
        }
    }
    return values;
}
/**
 * function to remove the commas and return the values sent from the client
 *
 */
vector<string> MyClientHandler::removeComma(char *buffer, int s) {
    string result;
    vector<string> values;
    for (int i = 0; i < s; i++) {
        if (buffer[i] == ' ') {
            continue;
        }
        if (buffer[i] == ',') {
            values.push_back(result);
            result.clear();
            continue;
        }
        if (buffer[i] == '\n' || buffer[i] == '\r' || buffer[i] == '\0') {
            values.push_back(result);
            result.clear();
            break;
        }
        result+=buffer[i];
    }
    return values;
}
/**
 * Clone the clientHandler.
 */
ClientHandler *MyClientHandler::Clone() {
    return new MyClientHandler(solver->Clone(), fileManager->Clone());
}
