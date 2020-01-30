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

template <class T>
class BestFirstSearch : public Searcher<T> {
protected:
    int numOfNodes;
public:
    string search(Searchable<T> * searchable) override;
    int getNumOfNodes() override;
    Searcher<T> *Clone() override;
};
/**
 * Search for the solution using ther BestFS algorithm
 * @tparam T
 * @param searchable
 * @return
 */
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
        numOfNodes++;
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

/**
 * Number of nodes evaluated.
 * @tparam T
 * @return number of nodes.
 */
template<class T>
int BestFirstSearch<T>::getNumOfNodes() {
    return this->numOfNodes;
}
/**
 * Clone the algorithm
 * @tparam T
 * @return new BestFirstSearch
 */
template<class T>
Searcher<T> *BestFirstSearch<T>::Clone() {
    return new BestFirstSearch();
}
/**
 * check if given node was examined or not.
 * @tparam T
 * @param node
 * @param PriQ
 * @return true if the node exists in the priority queue , false otherwise.
 */
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
#endif //MILESTONE_2_BESTFIRSTSEARCH_H
