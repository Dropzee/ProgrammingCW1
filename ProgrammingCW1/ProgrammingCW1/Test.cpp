#pragma once
#include "Encoder.h"
#include "Generator.h"

using namespace std;

int main() {

	string s;
	Encoder* e = new Encoder();

	try {
		s = e->read();
	}
	catch (const invalid_argument& iae) {
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}

	s = e->encode(s, 2, 3, 0, 1);

	e->write(s);

	system("pause");

	return 0;
}