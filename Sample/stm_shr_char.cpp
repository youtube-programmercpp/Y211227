#include "stm_shr_char.h"
#include <ctype.h>

std::istream& operator>>(std::istream& istm, char&& r)
{
	char ch;
	if (isgraph(static_cast<unsigned char>(r)) ? istm >> ch : istm.read(&ch, 1)) {
		//文字が読めた
		if (ch != r) {
			//異常（別の文字だった）
			istm.setstate(std::ios_base::failbit);//エラーフラグを設定する
		}
	}
	return istm;
}
