#include "greet.hh"
#include <iostream>

void greet()
{
    std::cout << "What's your name?" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
}