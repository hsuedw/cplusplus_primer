#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int n)
{
    int answer = 1;
    for (int i = 2; i <= n; ++i) {
        answer *= i;
    }
    return answer;
}

int main()
{
    int n;
    cout << "Please enter an integer: ";
    cin >> n;

    cout << n << "! = "  << fact(n) << endl;
    return 0;
}
