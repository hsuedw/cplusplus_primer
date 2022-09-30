#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int read_by_line(const string &file_name, vector<string> &lines)
{
    ifstream ifs(file_name);
    if (ifs.is_open()) {
        string line;
        while (getline(ifs, line)) {
           lines.push_back(line); 
        }

        ifs.close();
	return 0;
    }
    return -1;
}

int main()
{
    vector<string> lines;

    if (read_by_line("input_file.txt", lines) != 0) {
        cerr << "Cannot read file!" << endl;
	return -1;
    }

    for (auto &line : lines) {
        cout << line << endl;
    }

    return 0;
}
