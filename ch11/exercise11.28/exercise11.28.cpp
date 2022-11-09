#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

int main(int argc, char *argv[])
{
    map<string, vector<int>> data;
    data["hello"].push_back(1);
    data["hello"].push_back(2);
    data["hello"].push_back(3);

    map<string, vector<int>>::iterator it = data.find("hello");

    return 0;
}
