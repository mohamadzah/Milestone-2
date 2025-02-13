//
// Created by zahalka on 20/01/2020.
//

#ifndef MILESTONE_2_BFS_H
#define MILESTONE_2_BFS_H

#include "Searchable.h"
#include <queue>
#include "Searcher.h"
#include <iostream>
#include "State.h"
#include "CompareCost.h"
#include "Cell.h"
#include <stack>
#include "ToStringProblem.h"

//Note to self: this algorithm used FIFO data structure

template <class T>
class BFS : public Searcher<T> {
protected:
    int numOfNodes;
public:
    string search(Searchable<T> * searchable) override;
    int getNumOfNodes() override;
    Searcher<T> *Clone() override;
};

template<class T>
string BFS<T>::search(Searchable<T> *searchable) {
    State<T> * currentNode;
    vector<State<T> *> neighbors, solve;
    State<T> *initial = searchable->getInitialState();
    queue<State<T> *> queue;
    queue.push(initial);
    while (!queue.empty()) {
        currentNode = queue.front();
        queue.pop();
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
                    queue.push(item);
                    item->setVisitState(true);
                    item->setCost(currentNode->getCost() + item->getCost());
                }
            }
        }
    }
    return ToStringProblem::ToString(solve);
}
/**
 * Number of nodes
 * @tparam T
 * @return nodes evaluated.
 */
template<class T>
int BFS<T>::getNumOfNodes() {
    return this->numOfNodes;
}
/**
 * Clone the ALgorithm
 * @tparam T
 * @return new BFS algorithm
 */
template<class T>
Searcher<T> *BFS<T>::Clone() {
    return new BFS();
}


#endif //MILESTONE_2_BFS_H
