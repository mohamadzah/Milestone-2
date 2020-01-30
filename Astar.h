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
protected:
    int numOfNodes;
public:
    string search(Searchable<T> * searchable) override;
    int getNumOfNodes() override;
    Searcher<T> *Clone() override;
};
/**
 * In this function we return the shortest and most efficient path we could find
 * using the A*Star algorithm.
 *
 * @tparam T
 * @param searchable
 * @return the most efficient path
 */
template<class T>
string Astar<T>::search(Searchable<T> *searchable) {
    this->numOfNodes = 0;
    vector<State<T> *> neighbors;
    vector<State<T> *> solve;
    //create priority queue.
    priority_queue<State<T> *, vector<State<T> *>, CompareCost<T>> PriQ;
    //insert the initial. (start)
    PriQ.push(searchable->getInitialState());

    while (!PriQ.empty()) {
        //get the top node.
        State<T> * currentNode =  PriQ.top();
        //set its status to visited.
        currentNode->setVisitState(true);
        //erase it from the priority queue.
        PriQ.pop();

        numOfNodes++;
        //check if we reached the goal.
        if (searchable->isGoalState(currentNode)) {
            /* while (!searchable->isInitialState(currentNode)) {
                 currentNode = currentNode->getPrev();
                 solve.push_back(currentNode);
             }
             */
            //if we reached the goal state, we add the path to a vector and use the vector to get
            //a readable path.
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
                    if (v->getPrev() != nullptr) {
                        //use manhattan distance to get the cost.
                        double cost = Manhattan(searchable->goalState, v);
                        //if better cost.
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
    //get the path to return to the client.
    return ToStringProblem::ToString(solve);
}
/**
 * Return the number of nodes.
 * @tparam T
 * @return number of nodes evaluated.
 */
template<class T>
int Astar<T>::getNumOfNodes() {
    return this->numOfNodes;
}
/**
 * Clone the Astar algorithm
 * @tparam T
 * @return new Astar
 */
template<class T>
Searcher<T> *Astar<T>::Clone() {
    return new Astar();
}

/**
 * Check
 *
 * checks whether a certain state is already added to the priority queue or not.
 *
 * @tparam T
 * @param node
 * @param PriQ
 * @return whether state exists in priq or not.
 */
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
/**
 * manhattan distance function
 *
 * @param state
 * @param goalState
 * @return this function returns the distance between two points
 */
double Manhattan(State<Cell> *state, State<Cell> *goalState) {
    double dis = 0;
    dis = abs(state->getState().getRow() - goalState->getState().getRow()) +
          abs(state->getState().getColumn() - goalState->getState().getColumn());
    return dis;
}

#endif //MILESTONE_2_ASTAR_H