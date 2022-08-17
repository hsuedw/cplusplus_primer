#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int grade;
    cout << "Please enter a grade (0~100): ";
    cin >> grade;

    string finalgrade = (grade > 90) ? "high pass" 
                                     : (grade > 75) ? "pass"
                                     : (grade < 60) ? "fail" :"low pass";
    cout << finalgrade << endl;

    return 0;
}
