//
// Created by zahalka on 14/01/2020.
//

#include "FileCacheManager.h"
#include <iostream>
#include <fstream>
#include<sstream>


/**
 * Constructor.
 */
FileCacheManager::FileCacheManager() {
    //use # as seperator between problem and unique name
    ifstream file;
    file.open(FILE_NAME, ios::in);
    string line, name, unique;
    //we will read the unique names we created for the problems, load them into a map
    if (file.is_open()) {
        while (getline(file, line)) {
            hashUniques[line] = "matrix";
            if (line == "\n") {
                break;
            }
        }
    }
    file.close();
    string pr;
    string newP;
    string uniq;
    //now we will load the problems and their unique codes into the main map we will use (problemsCache).
    for (auto & item : hashUniques) {
        // # is the seperator i choose to distinguish between the problem and its unique code.
        auto find = item.first.find('#');
        if (find != string::npos) {
             newP = item.first.substr(0, find);
             uniq = item.first.substr(find+1, item.first.length());
        }
        file.open(uniq.c_str(), ios::in);
        if (file.is_open()) {
            problemsCache[newP] = uniq;
            file.close();
        }
    }
}
/**
 * Write problem and its unique code.
 * @param unique
 * @param problem
 */
void writeOld(const string& unique, const string& problem) {
    //write every problem and its unique code that we created for into into a single file.
    ofstream file;
    file.open(FILE_NAME, ios::out | ios::app);
    if (file.is_open()) {
        file << problem << "#" << unique << "\n";
    }
    file.close();
}
/**
 * Insert the problem and its unique code into the cache, and save the solution in disk.
 * @param pr
 * @param sl
 */
void FileCacheManager::insert(string pr, string sl) {
    string name = hashUnique(pr);
    problemsCache.insert({pr,name});
    //here we create the unique filename when inserting.
    //a map for problem with its unique name.
    //then all solutions will be on disk, when we need a soluton, we will read from the file.
    //save the problem in a file with unique name to problem
    writeFile(name, sl);
    writeOld(name, pr);
}
/**
 * If we have a solution, we will get it from the cache.
 * @param pr
 * @return the solution to a given problem.
 */
string FileCacheManager::get(string pr) {
    //read from the problems cache and return the solution.
    auto item = problemsCache.find(pr);
    string solution = readFile(item->second);
    return solution;
}
/**
 * check whether we have a solution in the cache or not.
 * @param pr
 * @return true if we have a solution already, else false.
 */
bool FileCacheManager::solExists(string pr) {
    //the problem will always be here. if we cant find it so that means we dont have a solution.
    if (problemsCache.count(pr) > 0) {
        return true;
    }
    string name = hashUnique(pr);
    return hashUniques.count(name) > 0;
}
/**
 * write the file into a file .
 * @param filename
 * @param solution
 */
void FileCacheManager::writeFile(const string& filename, const string& solution) {
    ofstream file;
    file.open(filename, ios::out);
    if (file.is_open()) {
        file << solution;
    }
    file.close();
}
/**
 * Read a solution from a file.
 * @param filename
 * @return the solution from file.
 */
string FileCacheManager::readFile(const string& filename) {
    ifstream file;
    string solution;
    //after we have checked that we have the problem, we send to this function the problem's unique filename and open it
    //read the solution and return it to the client.
    file.open(filename, ios::in);
    if (file.is_open()) {
        ostringstream ss;
        ss << file.rdbuf();
        solution = ss.str();
        file.close();
    }
    return solution;
}
/**
 * Hash a unique code out of a problem (string)
 * @param problem
 * @return unique filename
 */
string FileCacheManager::hashUnique(const string& problem) {
    hash<string> uniqueHash;
    auto file_name = uniqueHash(problem);
    return to_string(file_name);
}
/**
 * Clone the cache manager
 * @return
 */
CacheManager<string, string> *FileCacheManager::Clone() {
    return new FileCacheManager();
}


