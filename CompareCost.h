//
// Created by zahalka on 18/01/2020.
//

#ifndef MILESTONE_2_COMPARECOST_H
#define MILESTONE_2_COMPARECOST_H

#include "State.h"
/**
 * Compare the cost of two states.
 */
template <class T>
class CompareCost {
public:
    bool operator()(State<T> *state, State<T> *other) {
        return state->getCost() > other->getCost();
    };
};


#endif //MILESTONE_2_COMPARECOST_H
