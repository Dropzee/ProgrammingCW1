#pragma once
#include "Encoder.h"
#include "FileIO.h"

using namespace std;

void generator(string* outputs, string input, Encoder* e, FileIO* IO) {
	int count = 0;
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			for (int c = 0; c < 4; c++) {
				for (int d = 0; d < 4; d++) {
					outputs[count] = e->encode(input, a, b, c, d);
					IO->write(outputs[count], "XOR1(" + to_string(a) + "," + to_string(b) + ") XOR2(" + to_string(c) + "," + to_string(d) + ")");
					count++;
				}
			}
		}
	}
}

void compare(string* outputs) {

}

int main() {

	string input;
	string outputs[256];

	FileIO* IO = new FileIO();
	Encoder* e = new Encoder();

	try {
		input = IO->read("binaryFile.txt");
	}
	catch (const invalid_argument& iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}

	generator(&outputs[0], input, e, IO);

	system("pause");

	delete IO;
	delete e;

	return 0;
}