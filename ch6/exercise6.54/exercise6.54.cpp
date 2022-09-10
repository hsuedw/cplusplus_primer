#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int func(int, int);
vector<int (*)(int, int)> vecFunc1;

typedef int funcType(int, int);
vector<funcType *> vecFunc2;

vector<decltype(func) *> vecFunc3;

using funcType2 = int (int, int);
vector<funcType2 *> vecFunc4;

using funcPtr = int (*)(int, int);
vector<funcPtr> vecFunc5;

int func(int a, int b) {
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    vecFunc1.push_back(func);
    vecFunc2.push_back(func);
    vecFunc3.push_back(func);
    vecFunc4.push_back(func);
    vecFunc5.push_back(func);

    vecFunc1[0](11, 22);
    vecFunc2[0](33, 44);
    vecFunc3[0](55, 66);
    vecFunc4[0](77, 88);
    vecFunc5[0](99, 11);

    return 0;
}
