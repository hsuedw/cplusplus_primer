#include <iostream>

std::string global_str; // global_str is initialized to an empty string.
int global_int;         // global_int is initialized to 0.

int main()
{
    int local_int;         // The value of local_int is undefined.
    std::string local_str; // local_str is initialized to an empty string.

    std::cout << "global_str: [" << global_str << "]" << std::endl;
    std::cout << "global_int: " << global_int << std::endl;
    std::cout << "local_int: " << local_int << std::endl;
    std::cout << "local_str: [" << local_str << "]" << std::endl;

    return 0;
}

/*
 * g++ exercise2.10.cpp -o exercise2.10
 * $ ./exercise2.10
 * global_str: []
 * global_int: 0
 * local_int: 21962
 * local_str: []
 */
