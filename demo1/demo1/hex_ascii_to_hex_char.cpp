#include <iostream>
#include "hex_ascii_to_hex_char.h"
#include "Trans.h"

//高四位与低四位拆分
//ASCII码转字符，用trans程序

char Hex_ascii_to_Hex_char(char &data,char &low,char &high) {
	low = data &0x0f;
	//data = (data >> 4);
	high = (data >> 4) & 0x0f;
	low = trans(low);
	high = trans(high);
	return low, high;
}

