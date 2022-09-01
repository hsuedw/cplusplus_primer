#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t count_calls()
{
    static size_t cnt = 0;

    return cnt++;
}

int main()
{
    for (size_t i = 0; i < 10; ++i) {
        cout << count_calls() << endl;
    }

    return 0;
}
