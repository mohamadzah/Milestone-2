//
// Created by zahalka on 20/01/2020.
//

#ifndef MILESTONE_2_TOSTRINGPROBLEM_H
#define MILESTONE_2_TOSTRINGPROBLEM_H

#include "Cell.h"
#include <vector>
#include "string"

using namespace std;

class ToStringProblem {
public:
    string ToString(vector<State<Cell> *> solve) {
        string s;
        int rowNode, columnNode, rowNeighbor, columnNeighbor;
        for (int i = 0; i < solve.size(); i++) {
            rowNode = solve[i]->getState().getRow();
            rowNeighbor = solve[i+1]->getState().getRow();
            columnNode = solve[i]->getState().getColumn();
            columnNeighbor = solve[i+1]->getState().getColumn();
            //check the direction in which we need to go.
            if ((columnNode == columnNeighbor) && (rowNeighbor-1) == rowNode) {
                s+= "Up, ";
                s+= "(" + to_string(solve[i]->getCost()) + "), ";
            } else if ((columnNode == columnNeighbor) && (rowNeighbor+1) == rowNode) {
                s+= "Down, ";
                s+= "(" + to_string(solve[i]->getCost()) + "), ";
            } else if ((columnNode == columnNeighbor+1) && rowNeighbor == rowNode) {
                s+= "Right, ";
                s+= "(" + to_string(solve[i]->getCost()) + "), ";
            } else if ((columnNode == columnNeighbor-1) && rowNeighbor == rowNode) {
                s+= "Left, ";
                s+= "(" + to_string(solve[i]->getCost()) + "), ";
            }
        }
        return s;
    }
};


#endif //MILESTONE_2_TOSTRINGPROBLEM_H
