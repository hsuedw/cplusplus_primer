#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#if 0
// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2;
    // find the size of the smaller string; conditional operator, see section
    // 4.7 (p.151)
    auto size = (str1.size() < str2.size()) 
                ? str1.size() : str2.size();

    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return; // error #1: no return value; compiler should detect this error
    }
    // error #2: control might flow off the function without a return
    // teh compiler might not detect this error
}
#endif 

bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2;
    // find the size of the smaller string; conditional operator, see section
    // 4.7 (p.151)
    auto size = (str1.size() < str2.size()) 
                ? str1.size() : str2.size();

    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return false; 
    }

    return true;
}

int main(int argc, char *argv[])
{

    return 0;
}
