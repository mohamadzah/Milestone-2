//
// Created by zahalka on 14/01/2020.
//

#ifndef MILESTONE_2_CACHEMANAGER_H
#define MILESTONE_2_CACHEMANAGER_H

template <class Problem, class Solution>
class CacheManager {
public:
    //inserting into cache and a file
    virtual void insert(Problem pr, Solution sl) = 0;
    //get solution
    virtual Solution get(Problem pr) = 0;
    //check if solution exists.
    virtual bool solExists(Problem pr) = 0;
    //destructor
    virtual ~CacheManager() = default;
    //Clone the cachemanager.
    virtual CacheManager *Clone() = 0;
};

#endif //MILESTONE_2_CACHEMANAGER_H
