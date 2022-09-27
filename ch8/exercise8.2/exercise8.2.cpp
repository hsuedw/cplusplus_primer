#include <iostream>
#include <string>

using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;


istream& read_input(istream &is)
{
    is.clear();
    int num;

    while (is >> num, !is.eof()) {
	if (is.bad()) {
            cout << "Input stream error!" << endl;
            break;
	} else if (is.fail()) {
            cout << "Invalid input data! You should input string." << endl;
	    is.clear();
            is.ignore(1024, '\n');
	    continue;
	}

        cout << num;
    }

    is.clear();
    return is;
}


int main()
{
    read_input(cin);

    return 0;
}
