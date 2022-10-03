#include <list>
#include <string>
#include <iostream>

using std::list;
using std::string;
using std::cout;
using std::endl;


int main()
{
    list<string> lst_str = {"Hello world!", "How are you doing?"};

    cout << "============== Read elements in list<string>  ================" << endl;

    list<string>::const_iterator rd_cit = lst_str.cbegin();
    while (rd_cit != lst_str.cend()) {
        cout << *rd_cit << endl;
	++rd_cit;
    }
    cout << "-----------" << endl;

    list<string>::iterator rd_it = lst_str.begin();
    while (rd_it != lst_str.end()) {
        cout << *rd_it << endl;
	++rd_it;
    }
    cout << "-----------" << endl;

    list<string>::value_type str;
    rd_it = lst_str.begin();
    while (rd_it != lst_str.end()) {
        str = *rd_it;
        cout << str << endl;
	++rd_it;
    }
    cout << "-----------" << endl;

    for (list<string>::reference str_ref : lst_str) {
        cout << str_ref << endl;
    }
    cout << "-----------" << endl;

    for (list<string>::const_reference str_cref : lst_str) {
        cout << str_cref << endl;
    }

    cout << "============== Write elements in list<string>  ================" << endl;

    list<string>::iterator wr_it = lst_str.begin();
    while (wr_it != lst_str.end()) {
        *wr_it += " 1234";
	cout << *wr_it << endl;
        ++wr_it;
    }
    cout << "-----------" << endl;

    for (list<string>::reference str_ref : lst_str) {
        str_ref += "5678";
        cout << str_ref << endl;
    }

    return 0;
}
