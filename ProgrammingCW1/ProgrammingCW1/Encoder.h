#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Encoder
{
public:
	Encoder();
	~Encoder();
	string encode(string input, int xor1a, int xor1b, int xor2a, int xor2b);
private:
	string XOR(char a, char b);
};

