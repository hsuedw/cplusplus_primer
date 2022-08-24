#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int grade;
    cout << "Please enter a grade (0~100): ";
    cin >> grade;

    if (grade < 0 || 100 < grade) {
        cout << grade << " is an invalid grade." << endl;
	return -1;
    }

    string lettergrade;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    if (grade < 60) {
        lettergrade = scores[0];
    } else if (grade == 100) {
        lettergrade = scores[5];
    } else {
        // 60 <= grade < 100
	lettergrade = scores[(grade - 50) / 10];
        int ending = grade % 10;
	if (ending > 7) {
            lettergrade.push_back('+');
	} else if (ending < 3) {
            lettergrade.push_back('-');
	}
    }
    cout << "The letter grade is " << lettergrade << "." << endl;

    return 0;
}
