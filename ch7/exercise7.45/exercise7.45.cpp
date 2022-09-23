#include <vector>

using std::vector;

class NoDefault {
public:
    NoDefault(int a) {}
};

class C {
public:
    C(int i = 0) : c_member(i) {

    }
    NoDefault c_member;
};

int main()
{
    vector<C> vec(10);

    return 0;
}
