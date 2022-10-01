#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::ostringstream;
using std::istringstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;


istream& read_input(istream &is)
{
    is.clear();
    string word;

    while (is >> word, !is.eof()) {
	if (is.bad()) {
            cout << "Input stream error!" << endl;
            break;
	} else if (is.fail()) {
            cout << "Invalid input data! You should input string." << endl;
	    is.clear();
            is.ignore(1024, '\n');
	    continue;
	}

        cout << word << endl;
    }

    is.clear();
    return is;
}


int main()
{
    ostringstream msg;
    msg << "Hello World!" << endl;

    istringstream instr(msg.str());
    read_input(instr);

    return 0;
}
