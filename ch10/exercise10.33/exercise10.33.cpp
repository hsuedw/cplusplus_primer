#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char *argv[])
{
    string input_txt = "./input.txt";
    ifstream ifs(input_txt);
    if (!ifs) {
        cerr << "Cannot open " << input_txt << endl;
	exit(-1);
    }
    istream_iterator<int> ins_iter(ifs), eof;

    string even_txt = "./even.txt", odd_txt = "./odd.txt";
    ofstream ofs_even(even_txt), ofs_odd(odd_txt);
    if (!ofs_even) {
        cerr << "Cannot open " << even_txt << endl;
        exit(-1);
    }
    if (!ofs_odd) {
        cerr << "Cannot open " << odd_txt << endl;
        exit(-1);
    }
    ostream_iterator<int> even_iter(ofs_even, " "), odd_iter(ofs_odd, "\n");

    while (ins_iter != eof) {
        if (*ins_iter & 0x01) {
            // find an odd integer.
            *odd_iter++ = *ins_iter++;
        } else {
            // find an even integer.
            *even_iter++ = *ins_iter++;
        }
    }
    ofs_even << endl;

    return 0;
}
