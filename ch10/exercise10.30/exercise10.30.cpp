#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char *argv[])
{
    istream_iterator<int> is_iter(cin), eof;
    vector<int> nums;
    auto nums_back_iter = back_inserter(nums);

    while (is_iter != eof) {
        *nums_back_iter = *is_iter++;
    }

    sort(begin(nums), end(nums));

    ostream_iterator<int> os_iter(cout, " ");
    copy(begin(nums), end(nums), os_iter);
    cout << endl;

    return 0;
}
