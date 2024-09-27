#include "nfa.hh"

nfa_t init_nfa()
{
    nfa_t d;
    std::cout << "Please enter the alpha that the nfa needs (enter q to quit):";
    char alpha;
    while (std::cin >> alpha)
    {
        if (alpha == 'q')
            break;
        d.alpha.push_back(alpha);
    }

    std::cout << "Please enter the states that the nfa needs (q to quit):";
    int state;
    while (std::cin >> state)
    {
        d.states.insert(state);
    }

    std::cin.clear();
    std::cin.sync();

    while (true)
    {
        std::cout << "Please enter the start states (q to quit):";
        if (std::cin >> state)
        {
            if (d.states.find(state) != d.states.end())
            {
                d.start = state;
                break;
            }
            std::cout << "The start state is not in state set, please enter again" << std::endl;
        }
        else
        {
            break;
        }
    }

    std::cout << "Please enter the end states:";
    while (std::cin >> state)
    {
        if (d.states.find(state) != d.states.end())
        {
            d.end_states.insert(state);
        }
        else
        {
            std::cout << "State " << state << " is not in state set" << std::endl;
        }
    }
    std::cin.clear();
    std::cin.sync();

    std::cout << "Please enter the transition, format: <start_state> <input_char> <target_state>" << std::endl;
    int start_state;
    char input;
    int target_state;
    while (std::cin >> start_state >> input >> target_state)
    {
        if ((d.states.find(start_state) != d.states.end()) && (std::find(d.alpha.begin(), d.alpha.end(), input) != d.alpha.end()) && (d.states.find(target_state) != d.states.end()))
            d.transitions.insert(std::make_pair(start_state, std::make_pair(input, target_state)));
        else
        {
            std::cout << "State or char is invalid!" << std::endl;
        }
    }
    std::cin.clear();
    std::cin.sync();
    return d;
}

void nfa_info(nfa_t &d)
{
    // print the alpha list
    std::cout << "The alpha list of the nfa: ";
    for (std::vector<char>::iterator it = d.alpha.begin(); it != d.alpha.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // print the start state
    std::cout << "The start state of the nfa: ";
    std::cout << d.start;
    std::cout << std::endl;

    // print the nfa transitions
    std::cout << "The transitions of the nfa: " << std::endl;
    for (std::multimap<int, std::pair<char, int>>::iterator it = d.transitions.begin(); it != d.transitions.end(); it++)
    {
        std::cout << "Start: " << it->first << " Input: " << it->second.first << " End: " << it->second.second << std::endl;
    }
    std::cout << std::endl;

    // print the end states
    std::cout << "The end states of the nfa: ";
    for (std::set<int>::iterator it = d.end_states.begin(); it != d.end_states.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool simulate_helper(nfa_t &d, std::string &s, int current_state)
{
    if (s.empty() && d.end_states.find(current_state) != d.end_states.end())
    {
        return true;
    }
    bool valid = false;
    std::pair<std::multimap<int, std::pair<char, int>>::iterator, std::multimap<int, std::pair<char, int>>::iterator> nfa_pair = d.transitions.equal_range(current_state);
    for (std::multimap<int, std::pair<char, int>>::iterator it = nfa_pair.first; it != nfa_pair.second; it++)
    {
        if (it->second.first == s[0])
        {
            std::string substr = s.substr(1);
            valid = simulate_helper(d, substr, it->second.second);
            if (valid)
            {
                break;
            }
        }
    }
    return valid;
}

bool simulate(nfa_t &d, std::string &s)
{
    return simulate_helper(d, s, d.start);
}
