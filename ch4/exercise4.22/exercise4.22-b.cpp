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

    string finalgrade;
    if (grade > 90) {
        finalgrade = "high pass";
    } else if (grade > 75) {
        finalgrade = "pass";
    } else if (grade >= 60) {
        finalgrade = "low pass";
    } else {
        finalgrade = "fail";
    }

    cout << finalgrade << endl;

    return 0;
}
