//
// Created by zahalka on 15/01/2020.
//

#include "MyClientHandler.h"

template<class Problem, class Solution>
void MyClientHandler<Problem, Solution>::handleClient(int newSC) {
    vector<State<Cell> *> matrix;
    vector<vector<string>> values = readSolution(newSC);

    auto size = values.size() - 2;
    for (int i = 0; i < size; i++) {
        //set values.
        for (int k = 0; k < values[i].size(); k++) {
            auto it = values[i];
            State<Cell> * state;
            state = new State<Cell>(std::stod(it[k]),Cell(i,k));
        }
    }
}

template<class Problem, class Solution>
MyClientHandler<Problem, Solution>::MyClientHandler(Solver<Problem, Solution> *solver,
                                                    CacheManager<Problem, Solution> *fileManager) {
    this->solver = solver;
    this->fileManager = fileManager;
}

template<class Problem, class Solution>
vector<vector<string>> MyClientHandler<Problem, Solution>::readSolution(int newSC) {
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

template<class Problem, class Solution>
vector<string> MyClientHandler<Problem, Solution>::removeComma(char *buffer, int s) {
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
