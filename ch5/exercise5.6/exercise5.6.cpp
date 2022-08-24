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

    lettergrade = (grade < 60) ? scores[0] :
	                         (grade == 100) ? scores[5] : scores[(grade - 50) / 10];
    lettergrade += (grade < 60 || grade == 100) ? "" : 
	                          (grade % 10 > 7) ? "+" : 
				  (grade % 10 < 3) ? "-" : "";
    cout << "The letter grade is " << lettergrade << "." << endl;

    return 0;
}
