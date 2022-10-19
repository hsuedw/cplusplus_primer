#ifndef __DATE_H__
#define __DATE_H__

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;

class date {
public:
    date() : year(1900), month(1), day(1) {}
    date(string strDate);

    unsigned int getYear() const { return year; }
    unsigned int getMonth() const { return month; }
    unsigned int getDay() const { return day; }
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    const vector<string> month_name = {"January", "February", "March", "April",
                                       "May", "June", "July", "August", "September",
                                       "October", "November", "December"};
    const vector<string> month_short = {"Jan", "Feb", "Mar", "Apr", "May", "Jnu",
                                        "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
    const vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

date::date(string strDate)
{

}

ostream &operator<<(ostream &os, const date &d)
{
    os << d.getYear() << " " << d.getMonth() << " " << d.getDay();

    return os;
}

#endif //__DATE_H__
