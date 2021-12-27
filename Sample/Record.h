#pragma once
#include "YearMonthDay.h"
struct Record {
	YearMonthDay Date;
	double       Open;
	double       High;
	double       Low;
	double       Close;
	double       Adj_Close;
	int          Volume;
	friend std::istream& operator>>(std::istream& istm, Record& r);
	friend std::ostream& operator<<(std::ostream& ostm, const Record& r);
};
