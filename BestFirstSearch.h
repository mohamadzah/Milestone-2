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

template <class T>
class BestFirstSearch : public Searcher<T> {
public:
    string search(Searchable<T> * searchable) override;
};

template<class T>
string BestFirstSearch<T>::search(Searchable<T> *searchable) {

}

#endif //MILESTONE_2_BESTFIRSTSEARCH_H
