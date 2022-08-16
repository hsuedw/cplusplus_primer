#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    // (a)
    vector<string> vec = {"aa", "bb", "cc"};
    vector<string>::iterator iter = begin(vec);
    cout << *iter++ << endl;

    //iter = end(vec);
    //cout << *iter++ << endl; // legal but runtime error!
                               // iter referes to one past the end of vec.

    // (b)
    //(*iter)++; // illegal
    
    // (c)
    //*iter.empty(); // illegal

    // (d)
    iter->empty();

    //iter = end(vec) + 10000; // 
    //iter->empty();           // legal but runtime error!

    // (e)
    //++*iter; // illegal

    // (f)
    iter++->empty();

    return 0;
}
