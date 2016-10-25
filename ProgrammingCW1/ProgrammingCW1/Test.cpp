#pragma once
#include "Encoder.h"
#include "FileIO.h"
#include "UI.h"
#include <vector>

using namespace std;

//Generates all permutations and writes unique ones to file
void generator(vector<string> &outputs, vector<string> &names, string input, Encoder* e, FileIO* IO) {

	string temp;

	//All combinations from 0000 to 3333 in base 4
	for (int xor1a = 0; xor1a < 4; xor1a++) {
		for (int xor1b = 0; xor1b < 4; xor1b++) {
			for (int xor2a = 0; xor2a < 4; xor2a++) {
				for (int xor2b = 0; xor2b < 4; xor2b++) {

					//Encode using combination to indicate XOR inputs (0 = Input, 1 = R1, 2 = R2, 3 = R3)
					temp = e->encode(input, xor1a, xor1b, xor2a, xor2b);

					//Test to see if the output has occurred before
					bool unique = true;
					for each(string s in outputs) {
						if (s.compare(temp) == 0) {
							unique = false;
							break;
						}
					}

					//If it has not occurred before save it
					if (unique) {
						outputs.push_back(temp);
						string name = "XOR1(" + to_string(xor1a) + "," + to_string(xor1b) + ") XOR2(" + to_string(xor2a) + "," + to_string(xor2b) + ")";
						names.push_back(name);
						IO->write(temp, name);
					}
				}
			}
		}
	}
}

int main() {

	string input;
	vector<string> outputs;
	vector<string> names;

	FileIO* io = new FileIO();
	Encoder* e = new Encoder();
	UI* ui = new UI();

	try {
		input = io->read("binaryFile.txt");

		while (true) {
			switch (ui->menu()) {
			case 1:
				if (outputs.empty()) {
					generator(outputs, names, input, e, io);
					ui->generateAll(true);
				}
				else {
					ui->generateAll(false);
				}
			case 2:
				ui->inputCustom();
				break;
			case 3:
				ui->viewAll(names, outputs);
				break;
			case 4:
				goto Exit;
			default:
				cout << "Please enter a menu option between 1-5!" << endl;
			}
		}
	}
	catch (const invalid_argument& iae) {
		cout << iae.what() << endl;
		exit(1);
	}

Exit:
	delete io;
		delete e;
		delete ui;

		return 0;
}