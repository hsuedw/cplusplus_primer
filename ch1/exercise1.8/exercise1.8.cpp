#include <iostream>

int main()
{
    // Legal! Print `/*`.
    std::cout << "/*";

    // Legal! Print `*/`.
    std::cout << "*/";

    // Illegal! The right operand of << operator has a missing ".
    //std::cout << /* "*/" */;
    // Fix the error! Print ` */`
    std::cout << /* "*/" */";

    // Legal! Print ` /*   `.
    std::cout << /*  "*/" /*   "/*"   */;

    return 0;
}
