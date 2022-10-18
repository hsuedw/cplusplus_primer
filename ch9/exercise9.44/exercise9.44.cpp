#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void myReplace(string &s, const string &oldVal, const string &newVal)
{
    auto it = begin(s);
    while (it < end(s) - oldVal.size() + 1) {
        auto it2 = begin(oldVal);
	for (auto it3 = it; it2 != end(oldVal); ++it2, ++it3) {
            if (*it2 != *it3) {
                break;
            }
	}

	if (it2 == end(oldVal)) {
            // In s, find a substing and it matches oldVal.
            decltype(s.size()) pos = it - begin(s);
	    s.replace(pos, oldVal.size(), newVal, 0, newVal.size());

	    it = begin(s) + pos + newVal.size();
	} else {
            // In s, didn't find any substring that matches oldVal.
            ++it;
	}
    }
}

int main()
{
    string s = "r u ok?\ngo thru\ntho tho altho\nthrough thruu";

    cout << "old string: " << endl;
    cout << s << endl;
    cout << "------------------" << endl;

    myReplace(s, "tho", "though");
    cout << "Replace \"tho\" by \"though\": " << endl;
    cout << s << endl;
    cout << "------------------" << endl;

    myReplace(s, "thru", "through");
    cout << "Replace \"tho\" by \"though\": " << endl;
    cout << s << endl;

    return 0;
}
