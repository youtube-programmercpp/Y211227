#include "stm_shr_char.h"
#include <ctype.h>

std::istream& operator>>(std::istream& istm, char&& r)
{
	char ch;
	if (isgraph(static_cast<unsigned char>(r)) ? istm >> ch : istm.read(&ch, 1)) {
		//�������ǂ߂�
		if (ch != r) {
			//�ُ�i�ʂ̕����������j
			istm.setstate(std::ios_base::failbit);//�G���[�t���O��ݒ肷��
		}
	}
	return istm;
}
