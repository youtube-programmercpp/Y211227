#include "YearMonthDay.h"
#include "stm_shr_char.h"
#include <iomanip>

std::istream& operator>>(std::istream& istm, YearMonthDay& r)
{
	return istm >> r.year >> '-' >> r.month >> '-' >> r.day;
}
std::ostream& operator<<(std::ostream& ostm, const YearMonthDay& r)
{
	return ostm << r.year << '-'
		<< std::setfill('0')
		<< std::setw(2) << r.month << '-'
		<< std::setw(2) << r.day
		<< std::setfill(' ')
		;
}
