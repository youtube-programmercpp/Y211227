#pragma once
#include <istream>
#include <ostream>
struct YearMonthDay {
	int year;
	int month;
	int day;
	friend std::istream& operator>>(std::istream& istm, YearMonthDay& r);
	friend std::ostream& operator<<(std::ostream& ostm, const YearMonthDay& r);
};
