#include <map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>

using std::map;
using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

ostream &operator<<(ostream &os, map<vector<int>::iterator, int> &m)
{
    for (const auto &x : m) {
        os << x.second << " ";
    }

    return os;
}

//ostream &operator<<(ostream &os, map<list<int>::iterator, int> &m)
//{
//    for (const auto &x : m) {
//        os << x.second << " ";
//    }
//
//    return os;
//}

int main(int argc, char *argv[])
{
    map<vector<int>::iterator, int>  map_vec_it;
    //map<list<int>::iterator, int> map_lst_it;

    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        map_vec_it[it] = *it;
    }

    //list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //for (auto it = lst.begin(); it != lst.end(); ++it) {
    //    map_lst_it[it] = *it;
    //}

    cout << map_vec_it << endl;
    //cout << map_lst_it << endl;

    return 0;
}
