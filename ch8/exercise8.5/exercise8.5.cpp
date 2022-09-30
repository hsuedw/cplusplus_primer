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

int read_by_word(const string &file_name, vector<string> &words)
{
    ifstream ifs(file_name);
    if (ifs.is_open()) {
        string word;
        while (ifs >> word) {
            words.push_back(word); 
        }

        ifs.close();
	return 0;
    }
    return -1;
}


int main()
{
    vector<string> words;

    if (read_by_word("input_file.txt", words) != 0) {
        cerr << "Cannot read file!" << endl;
	return -1;
    }

    for (auto &word : words) {
        cout << word << endl;
    }

    return 0;
}
