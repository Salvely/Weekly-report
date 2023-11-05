#include "nfa.hh"
#include <string>

int main(void)
{
    /** init the nfa, which should match the format of an email */
    nfa_t d = init_nfa();
    
    /** print the nfa */
    nfa_info(d);

    std::string s;
    std::cout << "Input the text string you intend to verify:";
    std::cin >> s;

    /** check if the input email is valid */
    bool valid = simulate(d, s);
    if(valid) {
        std::cout << "The string is valid!" << std::endl;
    }
    else{
        std::cout << "The string is invalid!" << std::endl;
    }
}