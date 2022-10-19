#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    vector<string> nums = {"1.1", "2.2", "3.3", "4.4", "5.5", "6.6", "7.7", "8.8", "9.9"};
    double answer = 0.0;

    for (auto &s : nums) {
        answer += stod(s);
    }

    cout << answer << endl;

    return 0;
}
