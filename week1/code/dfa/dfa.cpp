#include "dfa.hh"

dfa_t init_dfa()
{
    dfa_t d;
    std::cout << "Please enter the alpha that the dfa needs:";
    char alpha;
    while (std::cin >> alpha)
    {
        d.alpha.push_back(alpha);
    }
    std::cout << "Please enter the states that the dfa needs:";
    int state;
    while (std::cin >> state)
    {
        d.states.insert(state);
    }
    while (true)
    {
        std::cout << "Please enter the start states:";
        std::cin >> state;
        if (d.states.find(state) != d.states.end())
        {
            d.start = state;
            break;
        }
        std::cout << "The end state is not in state set, please enter again" << std::endl;
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
            std::cout << "State " << state << "is not in state set" << std::endl;
        }
    }

    std::cout << "Please enter the transition, format: <start_state> <input_char> <target_state>" << std::endl;
    int start_state;
    char input;
    int target_state;
    while (std::cin >> start_state >> input >> target_state)
    {
        if ((d.states.find(start_state) != d.states.end()) && (std::find(d.alpha.begin(), d.alpha.end(), input) != d.alpha.end()) && (d.states.find(target_state) != d.states.end()))
            d.transitions.insert(std::make_pair(start_state, std::make_pair(input, target_state)));
        else {
            std::cout << "State or char is invalid!" << std::endl;
        }
    }
}

