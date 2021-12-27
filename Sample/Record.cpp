#include "Record.h"
#include "stm_shr_char.h"

std::istream& operator>>(std::istream& istm, Record& r)
{
	return istm
		>> r.Date >> ','
		>> r.Open >> ','
		>> r.High >> ','
		>> r.Low >> ','
		>> r.Close >> ','
		>> r.Adj_Close >> ','
		>> r.Volume
		;
}
std::ostream& operator<<(std::ostream& ostm, const Record& r)
{
	return ostm
		<< r.Date << ','
		<< r.Open << ','
		<< r.High << ','
		<< r.Low << ','
		<< r.Close << ','
		<< r.Adj_Close << ','
		<< r.Volume
		;
}
