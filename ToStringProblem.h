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
    /**
     * convert the vector that includes the path, to a path that the client can understand.
     *
     * @param solve
     * @return string that represents the path
     */
    static string ToString(vector<State<Cell> *> solve) {
        string s;
        int rowNode, columnNode, rowNeighbor, columnNeighbor;
        for (int i = 1; i < solve.size(); i++) {
            if (i != 1) {
                s+= ", ";
            }
            rowNode = solve[i]->getState().getRow();
            rowNeighbor = solve[i-1]->getState().getRow();
            columnNode = solve[i]->getState().getColumn();
            columnNeighbor = solve[i-1]->getState().getColumn();
            //check the direction in which we need to go.
            if ((columnNode == columnNeighbor) && (rowNeighbor-1) == rowNode) {
                s+= "Up ";
                s+= "(" + to_string((int)solve[i]->getCost()) + ")";
            } else if ((columnNode == columnNeighbor) && (rowNeighbor+1) == rowNode) {
                s+= "Down ";
                s+= "(" + to_string((int)solve[i]->getCost()) + ")";
            } else if ((columnNode == columnNeighbor+1) && rowNeighbor == rowNode) {
                s+= "Right ";
                s+= "(" + to_string((int)solve[i]->getCost()) + ")";
            } else if ((columnNode == columnNeighbor-1) && rowNeighbor == rowNode) {
                s+= "Left ";
                s+= "(" + to_string((int)solve[i]->getCost()) + ")";
            }
        }
        return s;
    }
};


#endif //MILESTONE_2_TOSTRINGPROBLEM_H
