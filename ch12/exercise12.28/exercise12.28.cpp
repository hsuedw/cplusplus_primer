#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

using std::vector;
using std::unordered_map;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::shared_ptr;

#define INPUT_FILE "./storyDataFile"

string filterWord(const string &tmpWord)
{
    string::size_type left = 0, right = tmpWord.size() - 1;
    while (!isalnum(tmpWord[left])) {
        ++left;
    }
    while (!isalnum(tmpWord[right])) {
        --right;
    }
    if (left > right) {
        return "";
    }
    return tmpWord.substr(left, right - left + 1);
}

void dbgPrint(vector<string> &text, unordered_map<string, set<int>> &wordToLineNum)
{
    cout << "text: "  << endl;
    for (vector<int>::size_type lineNum = 0; lineNum < text.size(); ++lineNum) {
        cout << "(line " << lineNum << ") " << text[lineNum] << endl;
    }
    cout << endl;

    cout << "wordToLineNum: " << endl;
    auto it = wordToLineNum.begin();
    while (it != wordToLineNum.end()) {
        cout << it->first << ": ";
        for (auto &lineNum : it->second) {
            cout << lineNum << " ";
        }
        ++it;
        cout << endl;
    }
    cout << endl;
}

string makePlural(set<int>::size_type n, const string &word, const string &suffix)
{
    return (n > 1) ? (word + suffix) : (word);
}

int main(int argc, char *argv[])
{
    ifstream ifs(INPUT_FILE);
    if (!ifs.is_open()) {
        cerr << "Cannot open input file: " << INPUT_FILE << endl;
        return -1;
    }

    string line;
    vector<string> text;
    unordered_map<string, set<int>> wordToLineNum;
    text.push_back(""); // The line number 0 is not used.
    // Process the input file and organize the data into 
    // the data structure in this program.
    for (int lineNum = 1; getline(ifs, line); ++lineNum) {
        text.push_back(line);

        istringstream iss(line);
        string tmpWord;
        while (iss >> tmpWord) {
            string word = filterWord(tmpWord); 
            wordToLineNum[word].insert(lineNum);
        }
    }

    //dbgPrint(text, wordToLineNum); // debug

    // run queries
    while (true) {
        cout << "enter word to look for, or q to quit: ";
	string s;

	// stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q") break;

        // run the query
        unordered_map<string, set<int>>::iterator queryIter = wordToLineNum.find(s);

        // print the results
        if (queryIter == wordToLineNum.end()) {
            cout << s << " occurs 0 times" << endl; 
            continue;
        }
        cout << s << " occurs " << queryIter->second.size()
             << makePlural(queryIter->second.size(), "time", "s") << endl;
	for (auto &lineNum : queryIter->second) {
            cout << "   (line " << lineNum << ") " << text[lineNum] << endl;
	}
    }

    return 0;
}
