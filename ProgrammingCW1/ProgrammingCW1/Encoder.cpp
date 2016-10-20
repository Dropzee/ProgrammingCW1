#include "Encoder.h"

Encoder::Encoder()
{
	/*registers[0] = '0';
	registers[1] = '0';
	registers[2] = '0';*/

	//XOR1[0] = 0; //Input Bit
	//XOR1[1] = 1; //Register 1
	//XOR2[0] = 2; //Register 2
	//XOR2[1] = 3; //Register 3
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

	for (int i = 0; i <= (input.length() - 2); i++) {
		//cout << *(registers + 0) << *(registers + 1) << *(registers + 2) << endl;

		//XOR
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

	Encoder* e = new Encoder();
	e->encode(s);

	system("pause");

	return 0;
}