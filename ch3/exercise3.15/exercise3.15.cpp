#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> vec;
    string word;
    while (cin >> word) {
        vec.push_back(word);
    }

    for (auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
