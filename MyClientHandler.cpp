//
// Created by zahalka on 15/01/2020.
//

#include "MyClientHandler.h"
#include "AlgorithmSearchable.h"

void MyClientHandler::handleClient(int newSC) {
    vector<State<Cell> *> matrix;
    vector<vector<string>> values = readSolution(newSC);

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

    //i will re order this later.
    int rowInitial = stoi(values[size][0]), columnInitial = stoi(values[size][1]);
    for (auto & i : matrix) {
        if ((i->getState().getRow() == rowInitial) && (i->getState().getColumn() == columnInitial)) {
            initialState = i;
            break;
        }
    }

    int rowGoal = stoi(values[size+1][0]), columnGoal = stoi(values[size+1][1]);
    for (auto & i : matrix) {
        if ((i->getState().getRow() == rowGoal) && (i->getState().getColumn() == columnGoal)) {
            goalState = i;
            break;
        }
    }
    //now we create a searchable.
    Searchable<Cell> *searchable = new AlgorithmSearchable(initialState, goalState, matrix);
    string check;
    if (this->fileManager->solExists(check)) {

    } else {
        string sol = this->solver->solve(searchable);
        int msg = write(newSC, sol.c_str(), strlen(sol.c_str()));
        if (msg < 0) {
            cerr << "error" << endl;
            exit(1);
        }
    }
}

MyClientHandler::MyClientHandler(Solver<Searchable<Cell> *, string> *solver, CacheManager<string, string> *fileManager) {
    this->solver = solver;
    this->fileManager = fileManager;
}

vector<vector<string>> MyClientHandler::readSolution(int newSC) {
    char buffer[1024] = {0};
    vector<vector<string>> values;
    vector<string> line;
    while (strcmp(buffer, "end") != 0) {
        int valread = read(newSC, buffer, 1024);

        if (valread < 0) {
            cerr << "Error reading from the client" << endl;
            exit(1);
        }

        line = removeComma(buffer, 1024);
        values.push_back(line);
    }

    return values;
}

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
        }
        if (buffer[i] == '\n' || buffer[i] == '\r') {
            break;
        }
        result+=buffer[i];
    }
    return values;
}
