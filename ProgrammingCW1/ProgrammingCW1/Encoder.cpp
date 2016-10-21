#include "Encoder.h"

Encoder::Encoder()
{
	inputPath = "binaryFile.txt";
}


Encoder::~Encoder()
{
}

string Encoder::encode(string input)
{
	//Append 000 as initial register state
	input += "000";

	//Set up pointer to registers
	char* registers = &input[input.length() - 4];

	//Initalise output string to allow appending
	string output = "";

	for (int i = 0; i <= (input.length() - 4); i++) {

		//XOR & add to output
		output += XOR(*(registers + 2), *(registers + 3));
		output += XOR(*(registers + 0), *(registers + 1));

		//Shift registers by moving pointer
		registers--;
	}

	return output;
}

string Encoder::XOR(char a, char b) {
	return to_string((((int)a + (int)b) % 2));
}

string Encoder::read(string path) throw (invalid_argument) {

	string input;

	ifstream data_file;
	string temp;

	data_file.open(path.c_str());

	if (data_file.fail()) {
		throw invalid_argument("no file exists " + path);
	}

	while (data_file >> temp) {
		input += temp;
	}

	data_file.close();

	return input;
}

void Encoder::write(string output) {
	ofstream myfile;
	myfile.open("test.txt");
	myfile << output;
	myfile.close();
}

int main() {

	string s;
	Encoder* e = new Encoder();

	try {
		s = e->read("binaryFile.txt");
	}
	catch (const invalid_argument& iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}

	s = e->encode(s);

	e->write(s);

	system("pause");

	return 0;
}