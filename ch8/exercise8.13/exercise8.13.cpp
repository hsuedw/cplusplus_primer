#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::istringstream;
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    ifstream ifs("input_data.txt");
    if (!ifs.is_open()) {
        cerr << "Cannot open input_data.txt." << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;

    istringstream record;
    while (getline(ifs, line)) {
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
