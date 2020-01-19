//
// Created by zahalka on 17/01/2020.
//

#include "AlgorithmSearchable.h"
#include <utility>
#include <cmath>

State<Cell> *AlgorithmSearchable::getInitialState() {
    return this->initialState;
}

bool AlgorithmSearchable::isGoalState(State<Cell> *state) {
    return (this->goalState == state);
}

vector<State<Cell> *> AlgorithmSearchable::getAllPossibleStates(State<Cell> *state) {
    int row, column, i = 0, stateRow, stateColumn;
    row = state->getState().getRow();
    column = state->getState().getColumn();
    vector<State<Cell> *> states;

    for (i = 0; i < possibleStates.size(); i++) {
        stateRow = possibleStates[i]->getState().getRow();
        stateColumn = possibleStates[i]->getState().getColumn();
        if ((stateColumn == column) && (stateRow == row-1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        if ((stateColumn == column) && (stateRow == row+1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        if ((stateColumn == column-1) && (stateRow == row)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        if ((stateColumn == column+1) && (stateRow == row)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
    }

    return states;
}

double AlgorithmSearchable::Manhattan(State<Cell> *state, State<Cell> *goalState) {
    double dis = 0;
    dis = abs(state->getState().getRow() - goalState->getState().getRow()) +
            abs(state->getState().getColumn() - goalState->getState().getColumn());
    return dis;
}

AlgorithmSearchable::AlgorithmSearchable(State<Cell> *_initialState, State<Cell> *_goalState,
                                         vector<State<Cell> *> _possibleStates) {
    initialState = _initialState;
    goalState = _goalState;
    possibleStates = std::move(_possibleStates);
}

