//
// Created by zahalka on 14/01/2020.
//

#ifndef MILESTONE_2_FILECACHEMANAGER_H
#define MILESTONE_2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include "map"
#include "unordered_map"
#include "vector"
#define FILE_NAME "problemData"

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
private:
    //<problem, uniquename>
    map<string, string> problemsCache;
    map<string, string> hashUniques;
public:
    FileCacheManager();
    //insert problem and solution.
    void insert(string pr, string sl) override;
    //return the solution to given problem.
    string get(string pr) override;
    //know if we have solution in o(1)
    bool solExists(string pr) override;
    //write solution in a file.
    void writeFile(const string& filename, const string& solution);
    //get solution.
    string readFile(const string& filename);
    //function to create a unique name out of string
    string hashUnique(const string& problem);
    //destructor
    ~FileCacheManager() override = default;
    //Clone the cache manager
    CacheManager<string, string>  *Clone() override;
};

#endif //MILESTONE_2_FILECACHEMANAGER_H
