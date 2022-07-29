#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    const string s = "Keep out!";
    for (auto& c : s) {
        c = 'x'; /* ERROR! */
    }
    cout << s << endl;

    return 0;
}
