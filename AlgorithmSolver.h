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
    Solver<Searchable<Cell>*, string> *Clone() override;
};
/**
 * Constructor
 *
 * @param _searcher
 */
AlgorithmSolver::AlgorithmSolver(Searcher<Cell> *_searcher) {
    this->searcher = _searcher;
}
/**
 * search for the solution
 * @param problem
 * @return the searcher's solve result
 */
string AlgorithmSolver::solve(Searchable<Cell> *problem) {
    return this->searcher->search(problem);
}
/**
 * Clone the solver.
 * @return new solver.
 */
Solver<Searchable<Cell> *, string> *AlgorithmSolver::Clone() {
    return new AlgorithmSolver(searcher->Clone());
}


#endif //MILESTONE_2_ALGORITHMSOLVER_H
