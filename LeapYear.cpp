#include <iostream>
#include <string>
using namespace std;


bool isLeapYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 4 == 0 && year % 100 != 0) return true;
	return false;
}

string dayOfProgrammer(int year)
{
    string res = "";
    bool leap = isLeapYear(year);
    if (leap == true)
    {
        string suffix = to_string(year);
        res = "12.09." + suffix;
    }
    else {
        string suffix = to_string(year);
        res = "13.09." + suffix;
    }
    return res;
}


int main()
{
    int year;
    cin >> year;
    cout << dayOfProgrammer(year);

	return 0;
}