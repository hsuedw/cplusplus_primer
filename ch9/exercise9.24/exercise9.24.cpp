#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

int main()
{
    int num;
    vector<int> iv;
    cout << "Please enter a sequence of integers: " << endl;
    while (cin >> num) {
        iv.push_back(num);
    }

    if (iv.empty()) {
        cerr << "There is no data!" << endl;
        return -1;
    }

    decltype(iv.size()) idx = 3;
    if (0 <= idx && idx < iv.size()) {
        cout << "iv.at(" << idx << ") is " << iv.at(idx) << endl;
        cout << "iv[" << idx << "] is " << iv[idx] << endl;
    } else {
        cerr << "idx = "  << idx << " is invalid." << endl;
    }
    cout << "iv.front() is " << iv.front() << endl;
    cout << "*iv.begin() is " << *iv.begin() << endl;

    return 0;
}
