#include "Encoder.h"

Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}

// ^ xor operator
string Encoder::encode(string input)
{
	//Append 000 as initial register state
	input += "000";

	//Set up pointer to registers
	char* registers = &input[input.length() - 3];

	//Initalise output string to allow appending
	string output = "start:";

	for (int i = 0; i <= (input.length() - 4); i++) {

		//XOR & add to output
		output += XOR(*(registers + 1), *(registers + 2));
		output += XOR(*(registers - 1), *(registers + 0));

		//Shift registers by moving pointer
		registers--;
	}

	cout << input.c_str() << endl;
	cout << output.c_str() << endl;

	return output;
}

char Encoder::XOR(char a, char b) {
	return (char)(((int)a + (int)b) % 2);
}

int main() {

	string s = "10110";
	cout << "Input: " << s.c_str() << endl;

	Encoder* e = new Encoder();

	s = e->encode(s);
	cout << "Output: " << s.c_str() << endl;

	system("pause");

	return 0;
}