#include <iostream>
#include <vector>
#include <algorithm>

#include "String.h"

using namespace std;

int main() {
    vector<String> vec;
    String s1("One");

    std::cout << std::endl << "----------- 1 ----------" << std::endl;
    vec.push_back(s1);

    std::cout << std::endl << "----------- 2 ----------" << std::endl;
    vec.push_back("Two");

    std::cout << std::endl << "----------- 3 ----------" << std::endl;
    vec.push_back(String("Three"));

    std::cout << std::endl << "----------- 4 ----------" << std::endl;
    vec.push_back(std::move(s1));

    return 0;
}
