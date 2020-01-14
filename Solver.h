//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_SOLVER_H
#define MILESTONE_2_SOLVER_H

template <class Problem, class Solution>
class Solver {
    virtual Solution solve(Problem pr) = 0;
    virtual ~Solver() = default;
};

#endif //MILESTONE_2_SOLVER_H
