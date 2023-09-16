#include <iostream>
#include <string>

#include "StrVec.h"

int main() {
    StrVec strs = {"Hello World",
                   "Hello Edward",
                   "Hello Angus",
                   "Hello Sophie",
                   "Hello John"};

    for (auto x : strs) {
        std::cout << x << std::endl;
    }

    return 0;
}
