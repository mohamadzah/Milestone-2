//
// Created by zahalka on 21/01/2020.
//

#ifndef MILESTONE_2_SOLVEPROBLEM_H
#define MILESTONE_2_SOLVEPROBLEM_H

#include "Cell.h"
#include "Searcher.h"
#include "Solver.h"

/**
 * not used!!
 */
class SolveProblem : public Solver<Searchable<Cell> *, string> {
    Searcher<Cell> * s;
public:
    explicit SolveProblem(Searcher<Cell> *search) {
        this->s = search;
    }

    string solve(Searchable<Cell>* searchable) override {
        return this->s->search(searchable);
    }
};


#endif //MILESTONE_2_SOLVEPROBLEM_H
