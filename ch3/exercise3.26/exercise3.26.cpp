#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string text = "abcdefghijklmnopqrstuvwxyz";
    char sought = 'x';
    auto beg = text.begin(), end = text.end();

    //auto mid = beg + (end - beg) / 2;
    auto mid = (beg + end) / 2;

    while (mid != end && *mid != sought) {
        if (sought < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        //mid = beg + (end - beg) / 2;
        mid = (beg + end) / 2;
    }

    cout << *mid << endl;

    return 0;
}
