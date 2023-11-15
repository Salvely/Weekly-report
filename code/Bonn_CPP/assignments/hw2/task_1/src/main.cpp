#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>

int main() {
    // generate a random number
    int number = 0;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 99);
    number = dist(rd);

    int input = 0;

    // simulate the guessing process
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cerr << "Error encountered, exiting..." << std::endl;
            std::cout << "The number is " << number << std::endl;
            exit(EXIT_FAILURE);
        } else if (input < 0 || input > 99) {
            std::cerr << "[WARNING] : Number must be between 0 and 99"
                      << std::endl;
            // fprintf(stderr, "[WARNING] : Number must be between 0 and 99");
            std::cout << "The number is " << number << std::endl;
            exit(EXIT_FAILURE);
        } else if (input == number) {
            std::cout << "You Win!" << std::endl;
            break;
        } else if (input < number) {
            std::cout << "The number is greater" << std::endl;
        } else if (input > number) {
            std::cout << "The number is smaller" << std::endl;
        }
    }
    std::cout << "The number is " << number << std::endl;
    exit(EXIT_SUCCESS);
}