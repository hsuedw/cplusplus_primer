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


void find_pattern(ifstream &in)
{
    string s, longest_word;
    int max_length = 0;

    while (in >> s) {
        if (s.find_first_of("bdfghjklpqty") != string::npos)
            continue;
        cout << s << " ";
        if (max_length < s.size()) {
            max_length = s.size();
	   longest_word = s; 
        }
    }

    cout << "The longest word: " << longest_word << endl;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Cannot open file: " << argv[1] << endl;
	return -1;
    }

    find_pattern(in);

    return 0;
}
