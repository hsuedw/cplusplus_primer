#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <iostream>

using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Account {
    static constexpr int period = 30;
    friend ostream &print(ostream &, const Account &);

public:
    Account() : Account ("", 0) {}
    explicit Account(const string &o, double b = 0.0) :
        owner(o), balance(b), daily_tbl() {}

    void addInterest() { balance += balance * interestRate; }
    ostream &print(ostream &);

    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    string owner;
    double balance;
    double daily_tbl[period];

    static double interestRate;
    static double initRate();
};

ostream &print(ostream &os, const Account &a)
{
    os << a.owner << " " << a.balance << endl;
    os << a.daily_tbl[0];
    return os;
}

#endif // _ACCOUNT_H_
