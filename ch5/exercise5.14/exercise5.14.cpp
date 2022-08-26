#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    char ch;
    string oneWord;
    vector<string> words;
    while (cin.get(ch)) {
        if (ch == ' ') {
            words.push_back(oneWord);
	    oneWord.clear();
        } else if (isalnum(ch)) {
            oneWord.push_back(ch);
        }
    }
    if (!oneWord.empty()) {
        words.push_back(oneWord);
    }

    auto iter = begin(words), maxIter = end(words);
    int maxCnt = 0, cnt = 1;
    while (iter != end(words) - 1) {
        if (*iter == *(iter + 1)) {
            ++cnt;
        } else {
            cnt = 1;
        }
	if (maxCnt < cnt) {
            maxCnt = cnt;
	    maxIter = iter;
        }
        ++iter;	
    }

    if (maxCnt > 0) {
        cout << *maxIter << " is repeated " << maxCnt << " times." << endl;
    }

    return 0;
}
