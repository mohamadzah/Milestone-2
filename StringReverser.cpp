//
// Created by zahalka on 15/01/2020.
//

#include "StringReverser.h"
#include "algorithm"

StringReverser::StringReverser() = default;
/**
 * reverse string
 * @param pr
 * @return string reversed.
 */
string StringReverser::solve(string pr) {
    string temp = pr;
    //reverse the string and send back.
    reverse(temp.begin(), temp.end());
    return temp;
}
