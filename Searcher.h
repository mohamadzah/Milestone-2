//
// Created by zahalka on 16/01/2020.
//

#ifndef MILESTONE_2_SEARCHER_H
#define MILESTONE_2_SEARCHER_H

#include "Searchable.h"
#include "iostream"
#include "string"

using namespace std;
/**
 * this interface will be implemnted by the searching algorithms.
 * @tparam T
 */
template <typename T>
class Searcher {
public:
    virtual string search(Searchable<T> * searchable) = 0;
    virtual int getNumOfNodes() = 0;
    virtual Searcher<T> *Clone() = 0;
};


#endif //MILESTONE_2_SEARCHER_H
