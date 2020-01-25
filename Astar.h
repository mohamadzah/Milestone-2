//
// Created by zahalka on 20/01/2020.
//

#ifndef MILESTONE_2_ASTAR_H
#define MILESTONE_2_ASTAR_H

#include "Searchable.h"
#include <queue>
#include "Searcher.h"
#include <iostream>
#include "State.h"
#include "CompareCost.h"
#include "Cell.h"
#include <stack>
#include "ToStringProblem.h"
#include "set"

template <class T>
class Astar : public Searcher<T> {
public:
    string search(Searchable<T> * searchable) override;
};

template<class T>
string Astar<T>::search(Searchable<T> *searchable) {
    vector<State<T> *> neighbors;
    vector<State<T> *> solve;
    //create priority queue.
    priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> PriQ;
    //insert the initial. (start)
    PriQ.push(searchable->getInitialState());

    while (!PriQ.empty()) {
        State<T> * currentNode =  PriQ.top();
        currentNode->setVisitState(true);
        PriQ.pop();
        //check if we reached the goal.
        if (searchable->isGoalState(currentNode)) {
            /* while (!searchable->isInitialState(currentNode)) {
                 currentNode = currentNode->getPrev();
                 solve.push_back(currentNode);
             }
             */
            State<T> * goal = searchable->goalState;
            while (goal->getPrev() != nullptr) {
                solve.insert(solve.begin(), goal);
                goal = goal->getPrev();
            }
            solve.insert(solve.begin(), goal);
        } else {
            neighbors = searchable->getAllPossibleStates(currentNode);
            //for each neighbor if not visited, we visit it.
            for (State<T> * v : neighbors) {
                if (v->getCost() == -1) {
                    continue;
                }
                if (!Check(v, PriQ) && !v->getVisit()) {
                    v->setCost(currentNode->getCost() + v->getCost());
                    v->setPrev(currentNode);
                    PriQ.push(v);
                } else {
                    double cost = Manhattan(searchable->goalState, v);
                    if (v->getPrev() != nullptr) {
                        if ((v->getCost()) > (v->getCost() - v->getPrev()->getCost() + currentNode->getCost() + cost)) {
                            if (!Check(v, PriQ)) {
                                v->setCost(v->getCost() - v->getPrev()->getCost() + currentNode->getCost() + cost);
                                v->setPrev(currentNode);
                                PriQ.push(v);
                            } else {
                                //update priority.
                                auto temp = PriQ.top();
                                PriQ.pop();
                                PriQ.push(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    return ToStringProblem::ToString(solve);
}

template<class T>
bool Check(State<T> *node, priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> PriQ) {
    while (!PriQ.empty()) {
        if (PriQ.top() == node) {
            return true;
        }
        PriQ.pop();
    }
    return false;
}

double Manhattan(State<Cell> *state, State<Cell> *goalState) {
    double dis = 0;
    dis = abs(state->getState().getRow() - goalState->getState().getRow()) +
          abs(state->getState().getColumn() - goalState->getState().getColumn());
    return dis;
}

#endif //MILESTONE_2_ASTAR_H