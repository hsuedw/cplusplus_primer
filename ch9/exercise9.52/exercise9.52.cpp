#include <stack>
#include <string>
#include <iostream>


using std::stack;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

// This program only takes parantheses and checks if they are matched correctly.
// I will try to deal with a real expression latter.

bool isMatch(string &expression)
{
    stack<char> st;

    for (string::size_type i = 0; i < expression.size(); ++i) {
        if (st.empty() || expression[i] == '(') {
            st.push(expression[i]);
	} else if (expression[i] == ')') {
            if (st.top() == '(') {
                st.pop();
            }
	}
    }

    return st.empty();
}

int main(int argc, char *argv[])
{
    string expression = "()";
    cout << expression << (isMatch(expression) ? " matches!" : " not matches!") << endl;

    expression = "(()";
    cout << expression << (isMatch(expression) ? " matches!" : " not matches!") << endl;

    expression = "()))";
    cout << expression << (isMatch(expression) ? " matches!" : " not matches!") << endl;

    return 0;
}
