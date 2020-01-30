//
// Created by zahalka on 13/01/2020.
//

#ifndef MILESTONE_2_SOLVER_H
#define MILESTONE_2_SOLVER_H
/**
 * Interface
 * @tparam Problem the matrix we will solve
 * @tparam Solution of the matrix.
 */
template <class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem pr) = 0;
    virtual ~Solver() = default;
    virtual Solver *Clone() = 0;
};

#endif //MILESTONE_2_SOLVER_H
