//
// Created by zahalka on 17/01/2020.
//

#include "AlgorithmSearchable.h"

State<Cell> *AlgorithmSearchable::getInitialState() {
    return this->initialState;
}

bool AlgorithmSearchable::isGoalState(State<Cell> *state) {
    return (this->goalState == state);
}

vector<State<Cell> *> AlgorithmSearchable::getAllPossibleStates(State<Cell> *state) {
    return vector<State<Cell> *>();
}

AlgorithmSearchable::AlgorithmSearchable(State<Cell> *_initialState, State<Cell> *_goalState,
                                         vector<State<Cell> *> _possibleStates) {
    initialState = _initialState;
    goalState = _goalState;
    possibleStates = _possibleStates;
}
