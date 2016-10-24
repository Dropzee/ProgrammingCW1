#pragma once
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

class FileIO
{
public:
	FileIO();
	~FileIO();
	string read(string path);
	void write(string output, string path);
};

