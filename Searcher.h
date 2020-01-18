//
// Created by zahalka on 16/01/2020.
//

#ifndef MILESTONE_2_SEARCHER_H
#define MILESTONE_2_SEARCHER_H

#include "Searchable.h"
#include "iostream"
#include "string"

using namespace std;

template <typename T>
class Searcher {
public:
    virtual string search(Searchable<T> * searchable) = 0;
};


#endif //MILESTONE_2_SEARCHER_H
