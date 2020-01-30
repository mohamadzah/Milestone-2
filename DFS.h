//
// Created by zahalka on 19/01/2020.
//

#ifndef MILESTONE_2_DFS_H
#define MILESTONE_2_DFS_H

#include "Searchable.h"
#include <queue>
#include "Searcher.h"
#include <iostream>
#include "State.h"
#include "CompareCost.h"
#include "Cell.h"
#include <stack>
#include "ToStringProblem.h"

template <class T>
class DFS : public Searcher<T> {
protected:
    int numOfNodes;
public:
    string search(Searchable<T> * searchable) override;
    int getNumOfNodes() override;
    Searcher<T> *Clone() override;
};

/**
 * Search for a solution using DFS algorithm
 * @tparam T
 * @param searchable
 * @return a path using DFS algorithm
 */
template<class T>
string DFS<T>::search(Searchable<T> *searchable) {
    State<T> * currentNode;
    vector<State<T> *> neighbors, solve;
    State<T> *initial = searchable->getInitialState();
    stack<State<T> *> stack;
    stack.push(initial);
    while (!stack.empty()) {
        currentNode = stack.top();
        stack.pop();
        //visit the current node
        currentNode->setVisitState(true);
        //check if we reached the goal or not.
        if (searchable->isGoalState(currentNode)) {
            //use a vector to help with writing to file, (more flexibility with checking values)
            State<T> * goal = searchable->goalState;
            while (goal->getPrev() != nullptr) {
                solve.insert(solve.begin(), goal);
                goal = goal->getPrev();
            }
            solve.insert(solve.begin(), goal);
        } else {
            neighbors = searchable->getAllPossibleStates(currentNode);
            for (auto item : neighbors) {
                if (!item->getVisit()) {
                    item->setPrev(currentNode);
                    stack.push(item);
                    item->setVisitState(true);
                    item->setCost(currentNode->getCost() + item->getCost());
                }
            }
        }
    }
    return ToStringProblem::ToString(solve);
}

/**
 * @tparam T
 * @return number of
 */
template<class T>
int DFS<T>::getNumOfNodes() {
    return this->numOfNodes;
}
/**
 * Clone the DFS Algorithm
 * @tparam T
 * @return
 */
template<class T>
Searcher<T> *DFS<T>::Clone() {
    return new DFS();
}


#endif //MILESTONE_2_DFS_H
