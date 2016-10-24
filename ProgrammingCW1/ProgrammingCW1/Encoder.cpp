#include "Encoder.h"

Encoder::Encoder()
{
	inputPath = "binaryFile.txt";
}


Encoder::~Encoder()
{
}

string Encoder::encode(string input, int xor1a, int xor1b, int xor2a, int xor2b)
{
	//Append 000 as initial register state
	input += "000";

	//Set up pointer to registers
	char* registers = &input[input.length() - 4];

	//Initalise output string to allow appending
	string output = "";

	for (int i = 0; i <= (input.length() - 4); i++) {

		//XOR & add to output
		output += XOR(*(registers + xor1a), *(registers + xor1b));
		output += XOR(*(registers + xor2a), *(registers + xor2b));

		//Shift registers by moving pointer
		registers--;
	}

	return output;
}

string Encoder::XOR(char a, char b) {
	return to_string((((int)a + (int)b) % 2));
}

string Encoder::read() throw (invalid_argument) {

	string input;

	ifstream file;
	string temp;

	file.open(inputPath.c_str());

	if (file.fail()) {
		throw invalid_argument("no file exists " + inputPath);
	}

	while (file >> temp) {
		input += temp;
	}

	file.close();

	return input;
}

void Encoder::write(string output) {
	ofstream myfile;
	myfile.open("test.txt");
	myfile << output;
	myfile.close();
}
