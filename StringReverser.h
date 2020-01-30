//
// Created by zahalka on 15/01/2020.
//

#ifndef MILESTONE_2_STRINGREVERSER_H
#define MILESTONE_2_STRINGREVERSER_H

#include "Solver.h"
#include "string"

using namespace std;
/**
 * reverse string
 *
 */
class StringReverser : public Solver<string, string> {

public:
    StringReverser();
    string solve(string pr) override;
    ~StringReverser() override = default;
};

#endif //MILESTONE_2_STRINGREVERSER_H
