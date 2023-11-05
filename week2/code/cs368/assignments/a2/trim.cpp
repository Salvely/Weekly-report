////////////////////////////////////////////////////////////////////////////////
// File Name:      trim.cpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The source file for trimming a string.
//
// IMPORTANT NOTE: THIS FILE SHOULD NOT BE MODIFIED.
//
// Code Source: The following 3 functions were originally written by Evan Teran
//              for the following question on stack overflow.
//
// Reference: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
////////////////////////////////////////////////////////////////////////////////

#include "trim.hpp"

#include <algorithm>
#include <functional>

// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(
                                            std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(
                                 std::ptr_fun<int, int>(std::isspace))).base(),
            s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
