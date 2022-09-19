#include <iostream>
#include "Trans.h"

//from ascii to hex_char_type

char trans(char &input) {

	if (input == 0) input = '0';
	else if (input == 1) input = '1';
	else if (input == 2) input = '2';
	else if (input == 3) input = '3';
	else if (input == 4) input = '4';
	else if (input == 5) input = '5';
	else if (input == 6) input = '6';
	else if (input == 7) input = '7';
	else if (input == 8) input = '8';
	else if (input == 9) input = '9';
	else if (input == 10) input = 'a';
	else if (input == 11) input = 'b';
	else if (input == 12) input = 'c';
	else if (input == 13) input = 'd';
	else if (input == 14) input = 'e';
	else if (input == 15) input = 'f';
	else {
		;
	}

	return input;
}

//from hex_char_type to int;

int reverse_trans(char ch,int &product) {
	if (ch == '0') product = 0;
	else if (ch == '1') product = 1;
	else if (ch == '2') product = 2;
	else if (ch == '3') product = 3;
	else if (ch == '4') product = 4;
	else if (ch == '5') product = 5;
	else if (ch == '6') product = 6;
	else if (ch == '7') product = 7;
	else if (ch == '8') product = 8;
	else if (ch == '9') product = 9;
	else if (ch == 'a') product = 10;
	else if (ch == 'b') product = 11;
	else if (ch == 'c') product = 12;
	else if (ch == 'd') product = 13;
	else if (ch == 'e') product = 14;
	else if (ch == 'f') product = 15;

	return product;
}