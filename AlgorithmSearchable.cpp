//
// Created by zahalka on 17/01/2020.
//

#include "AlgorithmSearchable.h"
#include <utility>

/**
 * getInitialState
 *
 * @return the initial state
 */
State<Cell> *AlgorithmSearchable::getInitialState() {
    return this->initialState;
}
/**
 * isGoalState
 *
 * used to check if we reached our goal state or not.
 *
 * @return whether the given state is the goal state or not
 */
bool AlgorithmSearchable::isGoalState(State<Cell> *state) {
    return (this->goalState == state);
}
/**
 * getAllPossibleStates
 *
 * Check every possible neighbor to a given state, and then return all the neighboring cells (up, down, left, right).
 *
 * @return neighboring cells (states)
 */
vector<State<Cell> *> AlgorithmSearchable::getAllPossibleStates(State<Cell> *state) {
    int row, column, i = 0, stateRow, stateColumn;
    row = state->getState().getRow();
    column = state->getState().getColumn();
    vector<State<Cell> *> states;

    for (i = 0; i < possibleStates.size(); i++) {
        stateRow = possibleStates[i]->getState().getRow();
        stateColumn = possibleStates[i]->getState().getColumn();
        //check if we have a neighbor from upwards
        if ((stateColumn == column) && (stateRow == row-1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        //check if we have a neighbor downwards
        if ((stateColumn == column) && (stateRow == row+1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        //check if we have a neighbor from to the right
        if ((stateColumn == column+1) && (stateRow == row)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        //check if we have a neighbor from to the left
        if ((stateColumn == column-1) && (stateRow == row)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        /*
        if ((stateColumn == column+1) && (stateRow == row+1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        if ((stateColumn == column-1) && (stateRow == row-1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        if ((stateColumn == column+1) && (stateRow == row-1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        if ((stateColumn == column-1) && (stateRow == row+1)) {
            if (possibleStates[i]->getCost() != -1) {
                states.push_back((possibleStates[i]));
            }
        }
        */
    }
    return states;
}
/**
 * Constructor
 *
 * @param _initialState
 * @param _goalState
 * @param _possibleStates
 */
AlgorithmSearchable::AlgorithmSearchable(State<Cell> *_initialState, State<Cell> *_goalState,
                                         vector<State<Cell> *> _possibleStates) {
    initialState = _initialState;
    goalState = _goalState;
    possibleStates = std::move(_possibleStates);
}
/**
 * isInitialState
 *
 * @param state
 * @return whether the state given is the initial state
 */
bool AlgorithmSearchable::isInitialState(State<Cell> *state) {
    return (this->initialState == state);
}

