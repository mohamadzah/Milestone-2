//
// Created by zahalka on 14/01/2020.
//

#ifndef MILESTONE_2_CACHEMANAGER_H
#define MILESTONE_2_CACHEMANAGER_H

template <class Problem, class Solution>
class CacheManager {
public:
    virtual void insert(Problem pr, Solution sl) = 0;
    virtual Solution get(Problem pr) = 0;
    virtual bool solExists(Problem pr) = 0;
    //destructor
    virtual ~CacheManager() = default;
};

#endif //MILESTONE_2_CACHEMANAGER_H
