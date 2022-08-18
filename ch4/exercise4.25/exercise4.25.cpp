#include <iostream>

using std::cout;
using std::endl;
using std::hex;

int main()
{
    // The bit pattern of 'q' is 0111 0001.
    // The the operator extends it to a 32-bit unsigned int, 
    // 0000 0000 0000 0000 0000 0000 0111 0001.
    // Because the precedence of the bitwise not operator (~) is higher
    // than the bitwise left shift operator (<<), the expression becomes
    // 1111 1111 1111 1111 1111 1111 1000 1110 << 6.
    // The perform the left shift operation and we have following result.
    // 1111 1111 1111 1111 1110 0011 1000 0000 = 0xffffe380
    // The result of ~'q' << 6 is 0xffffe380.
    cout << hex << (~'q' << 6) << endl;

    return 0;
}
