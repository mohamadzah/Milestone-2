//
// Created by zahalka on 14/01/2020.
//

#include "FileCacheManager.h"
#include <iostream>
#include <fstream>
#include<sstream>

FileCacheManager::FileCacheManager() {
    //use # as seperator between problem and unique name
    ifstream file;
    file.open(FILE_NAME, ios::in);
    string line, name, unique;
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
    for (auto & item : hashUniques) {
        auto find = item.first.find('#');
        if (find != string::npos) {
             newP = item.first.substr(0, find);
             uniq = item.first.substr(find+1, item.first.length());
        }
        cout << uniq << endl;
        file.open(uniq.c_str(), ios::in);
        if (file.is_open()) {
            problemsCache[newP] = uniq;
            cout << "in here" << endl;
            file.close();
        }
    }
}

void writeOld(const string& unique, const string& problem) {
    ofstream file;
    file.open(FILE_NAME, ios::out | ios::app);
    if (file.is_open()) {
        file << problem << "#" << unique << "\n";
    }
    file.close();
}

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

string FileCacheManager::get(string pr) {
    auto item = problemsCache.find(pr);
    string solution = readFile(item->second);
    return solution;
}

bool FileCacheManager::solExists(string pr) {
    //the problem will always be here. if we cant find it so that means we dont have a solution.
    if (problemsCache.count(pr) > 0) {
        return true;
    }
    string name = hashUnique(pr);
    return hashUniques.count(name) > 0;
}

void FileCacheManager::writeFile(const string& filename, const string& solution) {
    ofstream file;
    file.open(filename, ios::out);
    if (file.is_open()) {
        file << solution;
    }
    file.close();
}

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

string FileCacheManager::hashUnique(const string& problem) {
    hash<string> uniqueHash;
    auto file_name = uniqueHash(problem);
    return to_string(file_name);
}

CacheManager<string, string> *FileCacheManager::Clone() {
    return new FileCacheManager();
}


