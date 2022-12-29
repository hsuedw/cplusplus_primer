
#include <iostream>

#include "TextQuery.h"
#include "QueryResult.h"

using std::ostream;

typedef vector<string> textType;
typedef unordered_map<string, shared_ptr<set<TextQuery::lineNumType>>> w2lType;
typedef w2lType::const_iterator w2lIter;
typedef set<TextQuery::lineNumType> lineNumsType;
typedef shared_ptr<set<TextQuery::lineNumType>> lineNumsPtrType;
typedef lineNumsType::const_iterator lineNumsIter;

TextQuery::TextQuery(ifstream &ifs)
{
    string line;

    text = make_shared<textType>();
    wordToLineNum = make_shared<w2lType>();

    text->push_back(""); // Line number 0 is not used
    for (TextQuery::lineNumType lineNum = 1; getline(ifs, line); ++lineNum) {
        text->push_back(line);

        istringstream iss(line);
        string tmpWord;
        while (iss >> tmpWord) {
            string word = filterWord(tmpWord);
            auto &w2l = (*wordToLineNum);
            lineNumsPtrType &lineNums = w2l[word];
            if (!lineNums) {
                lineNums.reset(new lineNumsType());
            }
            lineNums->insert(lineNum);
        }
    }
}

void TextQuery::dbgPrint()
{
    textType &t = *text;
    cout << "text: " << endl;
    for (TextQuery::lineNumType i = 0; i < t.size(); ++i) {
        cout << "(line " << i << ") " << t[i] << endl;
    }
    cout << endl;

    w2lType &w2l = (*wordToLineNum);
    cout << "wordToLineNum: " << endl;
    w2lIter it = w2l.begin();
    while (it != w2l.end()) {
        const string &word = it->first;
        lineNumsPtrType lineNums = it->second;
        cout << word << ": ";
        for (auto &lineNum : *(lineNums)) {
            cout << lineNum << " ";
        }
        ++it;
        cout << endl;
    }
    cout << endl;
}

string TextQuery::filterWord(const string &tmpWord) {
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

QueryResult TextQuery::query(const string &word)
{
    w2lType &w2l = (*wordToLineNum);
    auto iter = w2l.find(word);
    if (iter == w2l.end()) {
        // word is not found.
	lineNumsPtrType noData(new lineNumsType());
	return QueryResult(word, text, noData);
    }

    // word is found.
    return QueryResult(word, text, iter->second);
}

// ------------------------------

string makePlural(set<int>::size_type n, const string &word, const string &suffix) 
{
    return (n > 1) ? (word + suffix) : (word);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.target << " occurs " << qr.lineNum->size() << " "
       << makePlural(qr.lineNum->size(), "time", "s") <<  endl;

    for (auto &num : *(qr.lineNum)) {
        os << "   (line " << num << ") " << qr.text->at(num) << endl;
    }

    return os;
}

