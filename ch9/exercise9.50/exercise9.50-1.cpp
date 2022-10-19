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
    vector<string> nums = {"11", "22", "33", "44", "55", "66", "77", "88", "99"};
    int answer = 0;

    for (auto &s : nums) {
        answer += stoi(s);
    }

    cout << answer << endl;

    return 0;
}
