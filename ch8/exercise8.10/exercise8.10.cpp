#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::istream;
using std::ifstream;
using std::ostringstream;
using std::istringstream;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    ifstream ifs("input_file.txt");
    if (!ifs.is_open()) {
        cerr << "Cannot open input_file.txt." << endl;
        return -1;
    }

    vector<string> lines;
    string line;
    while (getline(ifs, line)) {
        lines.push_back(line);
    }

    ifs.close();

    for (const string &tmpstr : lines) {
        istringstream iss(tmpstr);
        string word;
	while (iss >> word) {
            cout << word << endl;
	}
    }

    return 0;
}
