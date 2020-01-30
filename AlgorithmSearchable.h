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
    //constructor
    AlgorithmSearchable(State<Cell> * initialState, State<Cell> * goalState, vector<State<Cell> *> possibleStates);
    //return the initial state of the searchable object
    State<Cell> *getInitialState() override;
    //check whether the state sent is the goalState or not
    bool isGoalState(State<Cell> *state) override;
    //check whether the state sent is the initialState or not
    bool isInitialState(State<Cell> *state) override;
    //get all the possible states of a given state (i.e neighbors)
    vector<State<Cell>*> getAllPossibleStates(State<Cell> *state) override;
};

#endif //MILESTONE_2_ALGORITHMSEARCHABLE_H
