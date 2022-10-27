#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::ifstream;
using std::istream_iterator;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) 
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        cout << vec[i];
	if (i + 1 != vec.size()) {
            cout << " ";
	}
    }
    return os;
}

int main(int argc, char *argv[])
{
    string input_file = "./input.txt";

    ifstream ifs(input_file);
    if (!ifs) {
        cerr << "Cannot open " << input_file << endl;
	exit(-1);
    }

    istream_iterator<string> eof, ifs_iter(ifs);

    vector<string> vec;
    auto vec_back_iter = back_inserter(vec);
    while (ifs_iter != eof) {
         *vec_back_iter = *ifs_iter++;
    }

    cout << "vec: " << vec << endl;

    return 0;
}
