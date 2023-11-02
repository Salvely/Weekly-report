#ifndef _DFA_HH_
#define _DFA_HH_

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

/**
 * Before implementing the dfa, assuming that:
 * 1. The transisiton alpha is character
 * 2. The states are represented by integer.
 * 3. A states and their transitions is represented by a multimap,
 *  each state with different input char has a different transision
 */

// define the struct for dfa
typedef struct
{
    // an alpha list
    std::vector<char> alpha;

    // some states
    std::set<int> states;

    // states with their transitions
    std::multimap<int, std::pair<char, int>> transitions;

    // the starting state
    int start;

    // the ending states
    std::set<int> end_states;
} dfa_t;

// 
/**
 * @brief get user input and initialize the dfa
 * @return the dfa_t struct
 */
dfa_t init_dfa()



#endif