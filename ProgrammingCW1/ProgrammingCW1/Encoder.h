#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Encoder
{
public:
	Encoder();
	//Encoder(/*register setup?*/);
	~Encoder();
	string encode(string input);
	string read(string path);
	void write(string output);
private:
	string inputPath;
	string XOR(char a, char b);
};

