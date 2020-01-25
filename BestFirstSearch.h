//
// Created by zahalka on 18/01/2020.
//

#ifndef MILESTONE_2_BESTFIRSTSEARCH_H
#define MILESTONE_2_BESTFIRSTSEARCH_H

#include "Searchable.h"
#include <queue>
#include "Searcher.h"
#include <iostream>
#include "State.h"
#include "CompareCost.h"
#include "Cell.h"
#include "ToStringProblem.h"

/* https://courses.cs.washington.edu/courses/cse326/03su/homework/hw3/bestfirstsearch.html
  reference to the algorithm used. */

template <class T>
class BestFirstSearch : public Searcher<T> {
public:
    string search(Searchable<T> * searchable) override;
};

template<class T>
string BestFirstSearch<T>::search(Searchable<T> *searchable) {
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
                if (!Examined(v, PriQ) && !v->getVisit()) {
                    v->setCost(currentNode->getCost() + v->getCost());
                    v->setPrev(currentNode);
                    PriQ.push(v);
                } else {
                    double cost = Manhattan(searchable->goalState, v);
                    if (v->getPrev() != nullptr) {
                        if ((v->getCost()) > (v->getCost() - v->getPrev()->getCost() + currentNode->getCost())) {
                            if (!Examined(v, PriQ)) {
                                v->setCost(v->getCost() - currentNode->getCost() + v->getPrev()->getCost());
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
bool Examined(State<T> *node, priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> PriQ) {
    while (!PriQ.empty()) {
        if (PriQ.top() == node) {
            return true;
        }
        PriQ.pop();
    }
    return false;
}

template<class T>
priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> update(priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> PriQ) {
    priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> updated;
    while (!PriQ.empty()) {
        State<T> * newN = PriQ.pop();
        updated.push(newN);
    }
    return updated;
}

#endif //MILESTONE_2_BESTFIRSTSEARCH_H
