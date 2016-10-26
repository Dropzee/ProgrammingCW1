#include "Encoder.h"

Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

//Encode method
string Encoder::encode(string input, int xor1a, int xor1b, int xor2a, int xor2b)
{
	//Append 000 as initial register state
	input + "000" + input;

	//Set up pointer to registers
	char* registers = &input[0];

	//Initalise output string to allow appending
	string output = "";

	for (int i = 0; i <= (input.length() - 4); i++) {

		//XOR & add to output
		output += XOR(*(registers + xor1a), *(registers + xor1b));
		output += XOR(*(registers + xor2a), *(registers + xor2b));

		//Shift registers by moving pointer
		registers++;
	}

	//Reverse bit order
	return output;
}

//XOR Method
string Encoder::XOR(char a, char b) {
	return to_string((((int)a + (int)b) % 2));
}

