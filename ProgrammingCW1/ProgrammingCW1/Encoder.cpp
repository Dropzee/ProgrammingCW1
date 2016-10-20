#include "Encoder.h"

Encoder::Encoder()
{
	registers[0] = '0';
	registers[1] = '0';
	registers[2] = '0';

	XOR1[0] = 0; //Input Bit
	XOR1[1] = 1; //Register 1
	XOR2[0] = 2; //Register 2
	XOR2[1] = 3; //Register 3
}


Encoder::~Encoder()
{
}

// ^ xor operator
string Encoder::encode(string& input)
{

}