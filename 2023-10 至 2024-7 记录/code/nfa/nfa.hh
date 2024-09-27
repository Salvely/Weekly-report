#ifndef _NFA_HH_
#define _NFA_HH_

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

/**
 * Before implementing the nfa, assuming that:
 * 1. The transisiton alpha is character
 * 2. The states are represented by integer.
 * 3. A states and their transitions is represented by a multimap,
 *  each state with different input char has a different transision
 */

// define the struct for nfa
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
} nfa_t;

/**
 * @brief get user input and initialize the nfa
 * @return the nfa_t struct
 */
nfa_t init_nfa();

/**
 * @brief print the alpha list, states, nfa transitions, start state and end states of the nfa
 * 
 * @param d the nfa we have initialized
 */
void nfa_info(nfa_t& d);

/**
 * @brief simulate the nfa according to the input string
 * 
 * @param d the nfa to be simulate
 * @param s the input string
 * 
 * @return if s is a valid string according to the nfa
 */
bool simulate(nfa_t& d, std::string& s);
#endif