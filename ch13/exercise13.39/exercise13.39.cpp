#include <iostream>
#include <string>

#include "StrVec.h"

int main() {
    StrVec strs;
    std::string str1 = "Hello World";
    std::string str2 = "Hello Edward";
    std::string str3 = "Hello Angus";
    std::string str4 = "Hello Alice";

    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);
    strs.push_back(str4);

    for (auto x : strs) {
        std::cout << x << std::endl;
    }

    return 0;
}
