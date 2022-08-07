#include <iterator>
#include <iostream>

using std::begin;
using std::end;
using std::cout;
using std::endl;

bool is_equal(int *pbeg1, int *pend1, int *pbeg2, int *pend2)
{
    auto pit1 = pbeg1, pit2 = pbeg2;

    if (pend1 - pit1 != pend2 - pit2) {
        return false;
    }

    while (pit1 != pend1 && pit2 != pend2) {
        if (*pit1 != *pit2) {
            return false;
	}
	++pit1;
	++pit2;
    }
    return true;
}

int main()
{
    int ia1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ia2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ia3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int ia4[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "ia1 and ia2 are ";
    if (is_equal(begin(ia1), end(ia1), begin(ia2), end(ia2))) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    cout << "ia1 and ia3 are ";
    if (is_equal(begin(ia1), end(ia1), begin(ia3), end(ia3))) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    cout << "ia1 and ia4 are ";
    if (is_equal(begin(ia1), end(ia1), begin(ia4), end(ia4))) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    return 0;
}
