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
        State<T> * currentNode = PriQ.pop();

        //check if we reached the goal.
        if (searchable->isGoalState(currentNode)) {
            solve.push_back(currentNode);

            while (!searchable->isInitialState(currentNode)) {
                currentNode = currentNode->getPrev();
                solve.push_back(currentNode);
            }
            //solve and return solution.
            return solution(solve);
        } else {
            neighbors = searchable->getAllPossibleStates(currentNode);
            //for each neighbor if not visited, we visit it.
            for (State<T> * v : neighbors) {
                if (!v->is_visitedNode && !Examined(v, PriQ)) {
                        v->setCost(currentNode->getCost() + v->getCost());
                        v->setPrev(currentNode);
                        v->setVisitState(true);
                        PriQ.push(v);
                } else
                    if (v->getPrev() != nullptr) {
                        if ((v->getCost()) > (v->getCost()-v->getPrev()->getCost() + currentNode->getCost())) {
                            if (!v->is_visitedNode) {
                                v->setCost(v->getCost() - currentNode->getCost() + v->getPrev()->getCost());
                                v->setPrev(currentNode);
                                //update priority.
                                auto temp = PriQ.pop();
                                PriQ.pop();
                                PriQ.push(temp);
                            }
                        }
                }
            }
        }
    }
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

string solution(vector<State<Cell> *> solve) {
    string s;
    int rowNode, columnNode, rowNeighbor, columnNeighbor;
    for (int i = 0; i < solve.size(); i++) {
        rowNode = solve[i]->getState().getRow();
        rowNeighbor = solve[i+1]->getState().getRow();
        columnNode = solve[i]->getState().getColumn();
        columnNeighbor = solve[i+1]->getState().getColumn();
        //check the direction in which we need to go.
        if ((columnNode == columnNeighbor) && (rowNeighbor-1) == rowNode) {
            s+= "Up, ";
            s+= "(" + to_string(solve[i]->getCost()) + "), ";
        } else if ((columnNode == columnNeighbor) && (rowNeighbor+1) == rowNode) {
            s+= "Down, ";
            s+= "(" + to_string(solve[i]->getCost()) + "), ";
        } else if ((columnNode == columnNeighbor+1) && rowNeighbor == rowNode) {
            s+= "Right, ";
            s+= "(" + to_string(solve[i]->getCost()) + "), ";
        } else if ((columnNode == columnNeighbor-1) && rowNeighbor == rowNode) {
            s+= "Left, ";
            s+= "(" + to_string(solve[i]->getCost()) + "), ";
        }
    }
}

#endif //MILESTONE_2_BESTFIRSTSEARCH_H
