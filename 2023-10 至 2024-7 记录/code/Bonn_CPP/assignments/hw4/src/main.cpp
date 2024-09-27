#include <iostream>
#include <string>

#include "homework_4.h"

using namespace ipb;
int main(void) {
    named_vector<int> vec{"name", {5, 3, 5, 2, 1, 4}};
    std::cout << "---------" << std::endl;
    print(vec);
    sort(vec);
    print(vec);
    std::cout << "---------" << std::endl;
    std::cout << "accumulate:";
    std::cout << accumulate(vec) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "reverse:";
    reverse(vec);
    print(vec);
    std::cout << "---------" << std::endl;
    std::cout << "rotate 2 position:";
    rotate(vec, 2);
    print(vec);
    std::cout << "---------" << std::endl;
    std::cout << "find 2:";
    std::cout << std::boolalpha << find(vec, 2) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "clamp with [1,3]:";
    clamp(vec, 1, 3);
    print(vec);
    std::cout << "---------" << std::endl;
    std::cout << "count 1:";
    std::cout << count(vec, 1) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "fill:";
    fill(vec, 2);
    print(vec);
    std::cout << "---------" << std::endl;
    std::cout << "all_even:";
    std::cout << std::boolalpha << all_even(vec) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << vec.size() << std::endl;
    vec.resize(10);
    std::cout << vec.size() << std::endl;
    vec.resize(1);
    std::cout << vec.size() << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << vec.capacity() << std::endl;
    vec.reserve(30);
    std::cout << vec.capacity() << std::endl;
    std::cout << "---------" << std::endl;
}