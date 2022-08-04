#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto begIt = begin(scores);
    while (cin >> grade) {
        if (grade <= 100) {
            *(begIt + grade / 10) += 1;
        }
    }

    for (auto it = begin(scores); it != end(scores); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
