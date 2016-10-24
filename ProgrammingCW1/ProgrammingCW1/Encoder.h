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
	~Encoder();
	string encode(string input, int xor1a, int xor1b, int xor2a, int xor2b);
	string read();
	void write(string output);
private:
	string inputPath;
	string XOR(char a, char b);
};

