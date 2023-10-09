#include <iostream>
#include <fstream>

#include "TextQuery.h"
#include "QueryResult.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;

#define INPUT_FILE "./storyDataFile"


void runQueries(ifstream &infile)
{
    // infile  is an ifstream that is the file we want ot query
    TextQuery tq(infile); // store the file and build the query map

    // iterate with user: prompt for a word to find and print results
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;

        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q") break;

        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream ifs(INPUT_FILE);
    if (!ifs.is_open()) {
        cerr << "Cannot open input file: " << INPUT_FILE << endl;
	return -1;
    }

    //TextQuery tq(ifs);
    //tq.dbgPrint();
    //print(cout, tq.query("Daddy")) << endl;

    runQueries(ifs);

    return 0;
}
