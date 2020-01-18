//
// Created by zahalka on 15/01/2020.
//

#ifndef MILESTONE_2_SEARCHABLE_H
#define MILESTONE_2_SEARCHABLE_H

#include "State.h"
#include "vector"
#include "iostream"

using namespace std;

template <typename T>
class Searchable {
protected:
    State<T> * initialState;
    State<T> * goalState;
    vector<State<T> *> possibleStates;
public:
    virtual State<T> *getInitialState() = 0;
    virtual bool isGoalState(State<T> *state) = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T> *state) = 0;
};

#endif //MILESTONE_2_SEARCHABLE_H
