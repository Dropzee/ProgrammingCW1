#include "FileIO.h"

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}


string FileIO::read(string path) throw (invalid_argument) {

	string input;

	ifstream file;
	string temp;

	file.open(path.c_str());

	if (file.fail()) {
		throw invalid_argument("no file exists " + path);
	}

	while (file >> temp) {
		input += temp;
	}

	file.close();

	return input;
}

void FileIO::write(string output, string name) {
	ofstream myfile;
	myfile.open("Outputs\\" + name + ".txt");
	myfile << output;
	myfile.close();
}