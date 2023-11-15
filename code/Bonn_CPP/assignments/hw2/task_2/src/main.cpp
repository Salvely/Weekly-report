#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./task_2 <file1> <file2>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<std::pair<int, std::string>> vec;
    int number = 0;
    std::string ext;

    for (int i = 1; i < argc; i++) {
        std::istringstream is(argv[i]);

        is >> number >> ext;
        if (is.fail()) {
            std::cerr << "Input Invalid" << std::endl;
            exit(EXIT_FAILURE);
        }
        vec.emplace_back(std::make_pair(number, ext));
    }

    double result = 0;
    if (vec[0].second == ".txt" && vec[1].second == ".txt") {
        result = (vec[0].first + vec[1].first) / 2;

    } else if (vec[0].second == ".png" && vec[1].second == ".png") {
        result = (vec[0].first + vec[1].first);
    } else if (vec[0].second == ".txt" && vec[1].second == ".png") {
        result = vec[0].first % vec[1].first;
    } else {
        std::cerr << "Extension Invalid!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << result << std::endl;
    exit(EXIT_SUCCESS);
}