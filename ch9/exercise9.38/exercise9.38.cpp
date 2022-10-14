#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::ostream;

template<typename T> ostream &operator<<(ostream &os, vector<T> &c)
{
    auto it = begin(c);
    while (it != end(c)) {
        os << *it << " ";
	++it;
    }
    return os;
}

int main()
{
    vector<int> iv;
    cout << "1. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.push_back(0);
    cout << "2. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.push_back(0);
    cout << "3. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.push_back(0);
    cout << "4. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.push_back(0);
    iv.push_back(0);
    cout << "5. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    while (iv.size() < iv.capacity()) {
        iv.push_back(0);
    }
    iv.push_back(0);
    cout << "6. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.reserve(5);
    cout << "7. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.reserve(50);
    cout << "8. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    while (iv.size() < iv.capacity()) {
        iv.push_back(0);
    }
    iv.push_back(0);
    cout << "9. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.resize(iv.size() + iv.size() / 2);
    cout << "10. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.resize(iv.size() * 2);
    cout << "11. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.push_back(0);
    cout << "12. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    iv.shrink_to_fit();
    cout << "13. size: " << iv.size() << ", capacity: " << iv.capacity() << endl;

    return 0;
}
