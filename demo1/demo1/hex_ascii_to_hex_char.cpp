#include <iostream>
#include "hex_ascii_to_hex_char.h"
#include "Trans.h"

//����λ�����λ���
//ASCII��ת�ַ�����trans����

char Hex_ascii_to_Hex_char(char &data,char &low,char &high) {
	low = data &0x0f;
	//data = (data >> 4);
	high = (data >> 4) & 0x0f;
	low = trans(low);
	high = trans(high);
	return low, high;
}

