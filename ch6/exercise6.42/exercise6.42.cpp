#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string word = "success";
    cout << "The singular form of " << word << " is " 
	 << make_plural(1, word, "es") << "." << endl;
    cout << "The plural form of " << word << " is " 
	 << make_plural(2, word, "es") << "." << endl;

    word = "failure";
    cout << "The singular form of " << word << " is " 
	 << make_plural(1, word, "s") << "." << endl;
    cout << "The plural form of " << word << " is " 
	 << make_plural(2, word) << "." << endl;

    return 0;
}
