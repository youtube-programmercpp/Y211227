#include "Record.h"
#include "stm_shr_char.h"
#include <string>
#include <fstream>
#include <iostream>

int main()
{
	if (std::ifstream file{ "^N225.csv" }) {
		if (file.ignore(std::numeric_limits<std::streamsize>::max(), '\n')) {
			for (Record d; file >> d >> '\n';)
				std::cout << d << '\n';
		}
	}
}
