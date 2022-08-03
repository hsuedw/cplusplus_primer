#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() 
{
    vector<string> text;
    string line;
    while (getline(cin, line)) {
        text.push_back(line);
    }

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto c = (*it).begin(); c != (*it).end(); ++c) {
            if (isalpha(*c)) {
	        *c = toupper(*c);
	    }
        }
    }

    for (auto& t : text) {
        cout << t << endl;
    }

    return 0;
}
