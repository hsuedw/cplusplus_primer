#include <iostream>
using namespace std;

int main()
{
    int *ip = nullptr;
    std::cout << ip << std::endl;
    if (ip) {
        std::cout << "ip points to a valid object." << std::endl; 
    } else {
        std::cout << "ip does not point to a valid object." << std::endl; 
    }
   
    ip = new int[100];
    std::cout << ip << std::endl;

    delete ip;
    std::cout << ip << std::endl;

    if (ip) {
        std::cout << "After the object ip points to is deleted." << std::endl; 
    }
    //ip[0] = 3; // This might crash the program.

    return 0;
}
