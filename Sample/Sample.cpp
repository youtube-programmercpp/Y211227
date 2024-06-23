#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <iomanip>

std::istream& operator>>(std::istream& istm, char&& r)
{
	char ch;
	if (isgraph(r) ? istm >> ch : istm.read(&ch, 1)) {
		//文字が読めた
		if (ch != r) {
			//異常（別の文字だった）
			istm.setstate(std::ios_base::failbit);//エラーフラグを設定する
		}
	}
	return istm;
}

struct YearMonthDay {
	int year;
	int month;
	int day;

	friend std::istream& operator>>(std::istream& istm, YearMonthDay& r)
	{
		return istm >> r.year >> '-' >> r.month >> '-' >> r.day;
	}
	friend std::ostream& operator<<(std::ostream& ostm, const YearMonthDay& r)
	{
		return ostm << r.year << '-'
			<< std::setfill('0')
			<< std::setw(2) << r.month << '-'
			<< std::setw(2) << r.day
			<< std::setfill(' ')
			;
	}
};
struct Record {
	YearMonthDay Date;
	double       Open;
	double       High;
	double       Low;
	double       Close;
	double       Adj_Close;
	int          Volume;
	friend std::istream& operator>>(std::istream& istm, Record& r)
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
	friend std::ostream& operator<<(std::ostream& ostm, const Record& r)
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
};

int main()
{
	std::ifstream file("^N225.csv");
	if (file) {
		for (Record d; file >> d >> '\n';)
			std::cout << d << '\n';
	}
}
