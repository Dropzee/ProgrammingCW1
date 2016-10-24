#pragma once
#include "Encoder.h"
#include "FileIO.h"
#include <vector>
#include <algorithm>

using namespace std;

void generator(vector<string> outputs, string input, Encoder* e, FileIO* IO) {
	string temp;
	for (int xor1a = 0; xor1a < 4; xor1a++) {
		for (int xor1b = 0; xor1b < 4; xor1b++) {
			for (int xor2a = 0; xor2a < 4; xor2a++) {
				for (int xor2b = 0; xor2b < 4; xor2b++) {
					temp = e->encode(input, xor1a, xor1b, xor2a, xor2b);
					bool unique = true;
					for each(string s in outputs) {
						if (s.compare(temp) == 0) {
							unique = false;
							break;
						}
					}
					if (unique) {
						outputs.push_back(temp);
						IO->write(temp, "XOR1(" + to_string(xor1a) + "," + to_string(xor1b) + ") XOR2(" + to_string(xor2a) + "," + to_string(xor2b) + ")");
					}
				}
			}
		}
	}
}

int main() {

	string input;
	vector<string> outputs;

	FileIO* IO = new FileIO();
	Encoder* e = new Encoder();

	try {
		input = IO->read("binaryFile.txt");
	}
	catch (const invalid_argument& iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}

	generator(outputs, input, e, IO);

	system("pause");

	delete IO;
	delete e;

	return 0;
}