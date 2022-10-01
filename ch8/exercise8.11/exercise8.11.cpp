#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::istringstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;

    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;
	record.clear();
	record.str(line);
	record >> info.name;
	while (record >> word) 
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &p : people) {
        cout << "name: " << p.name << endl;
	cout << "phones: ";
	for (const auto &x : p.phones) {
            cout << x << " ";
	}
	cout << endl;
    }

    return 0;
}
