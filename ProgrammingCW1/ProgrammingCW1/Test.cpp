#pragma once
#include "Encoder.h"
#include "FileIO.h"
#include <vector>

using namespace std;

void generator(string* outputs, string input, Encoder* e, FileIO* IO) {
	int count = 0;
	for (int xor1a = 0; xor1a < 4; xor1a++) {
		for (int xor1b = 0; xor1b < 4; xor1b++) {
			for (int xor2a = 0; xor2a < 4; xor2a++) {
				for (int xor2b = 0; xor2b < 4; xor2b++) {
					outputs[count] = e->encode(input, xor1a, xor1b, xor2a, xor2b);
					IO->write(outputs[count], "XOR1(" + to_string(xor1a) + "," + to_string(xor1b) + ") XOR2(" + to_string(xor2a) + "," + to_string(xor2b) + ")");
					count++;
				}
			}
		}
	}
}

void compare(string* outputs) {
	for (int i = 0; i < 256; i++) {
		vector<int> matches;
		for (int j = 0; j < 256; j++) {
			if (i != j) {
				if (outputs[i].compare(outputs[j]) == 0) {
					matches.push_back(j);
				}
			}
		}
	}
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