//
// Created by zahalka on 17/01/2020.
//

#ifndef MILESTONE_2_ALGORITHMSEARCHABLE_H
#define MILESTONE_2_ALGORITHMSEARCHABLE_H

#include "Searchable.h"
#include <vector>
#include "Cell.h"
#include "State.h"

class AlgorithmSearchable : public Searchable<Cell> {
public:
    AlgorithmSearchable(State<Cell> * initialState, State<Cell> * goalState, vector<State<Cell> *> possibleStates);
    //functions from searchable.
    State<Cell> *getInitialState() override;
    bool isGoalState(State<Cell> *state) override;
    vector<State<Cell>*> getAllPossibleStates(State<Cell> *state) override;
    double Manhattan(State<Cell> * state, State<Cell> *goalState);
};

#endif //MILESTONE_2_ALGORITHMSEARCHABLE_H
