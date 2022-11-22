#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <new>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::nothrow;

vector<int> *factory()
{
    return new(nothrow) vector<int>();
}

void populateVec(vector<int> *pv)
{
    int num;
    while (cin >> num) {
        pv->push_back(num);
    }
}

void printVec(vector<int> *pv)
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
    vector<int> *pv = factory();
    if (pv != nullptr) {
        populateVec(pv);
        printVec(pv);
        delete pv;
        pv = nullptr;
    }

    return 0;
}
