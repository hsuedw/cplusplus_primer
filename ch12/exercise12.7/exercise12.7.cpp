#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> factory()
{
    return make_shared<vector<int>> ();
}

void populateVec(shared_ptr<vector<int>> pv)
{
    int num;
    while (cin >> num) {
        pv->push_back(num);
    }
}

void printVec(shared_ptr<vector<int>> pv)
{
    vector<int>::size_type i = 0;
    while (i < pv->size()) {
        cout << (*pv)[i];
	if (i + 1 != pv->size()) {
            cout << ", ";
	}
        ++i;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    auto pv = factory();
    populateVec(pv);
    printVec(pv);

    return 0;
}
