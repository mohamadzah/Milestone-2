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
public:
    string search(Searchable<T> * searchable) override;
};

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
            solve.push_back(currentNode);
            while (!searchable->isInitialState(currentNode)) {
                currentNode = currentNode->getPrev();
                solve.push_back(currentNode);
            }
        } else {
            neighbors = searchable->getAllPossibleStates(currentNode);
            for (auto item : neighbors) {
                if (item->getCost() == -1) {
                    break;
                }
                if (!item.getVisit()) {
                    item->setPrev(currentNode);
                    stack.push(item);
                   // item->setCost(currentNode->getCost() + item->getCost());
                }
            }
        }
    }

    return ToStringProblem::ToString(solve);
}

#endif //MILESTONE_2_DFS_H
