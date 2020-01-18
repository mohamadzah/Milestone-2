//
// Created by zahalka on 14/01/2020.
//

#ifndef MILESTONE_2_FILECACHEMANAGER_H
#define MILESTONE_2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include "map"

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
private:
    map<string, string> problemsCache;
public:
    FileCacheManager();
    void insert(string pr, string sl) override;

};

#endif //MILESTONE_2_FILECACHEMANAGER_H
