//
// Created by zahalka on 19/01/2020.
//

#ifndef MILESTONE_2_ALGORITHMSOLVER_H
#define MILESTONE_2_ALGORITHMSOLVER_H

#include "Cell.h"
#include "Solver.h"
#include "Searcher.h"
#include "State.h"

class AlgorithmSolver : public Solver<Searchable<Cell>*, string> {
    Searcher<Cell> * searcher;
public:
    explicit AlgorithmSolver(Searcher<Cell> * _searcher);
    string solve(Searchable<Cell> * problem) override;

};

AlgorithmSolver::AlgorithmSolver(Searcher<Cell> *_searcher) {
    this->searcher = _searcher;
}

string AlgorithmSolver::solve(Searchable<Cell> *problem) {
    return this->searcher->search(problem);
}


#endif //MILESTONE_2_ALGORITHMSOLVER_H
