#pragma once
#include <iostream>

using namespace std;

class Encoder
{
public:
	Encoder();
	//Encoder(/*register setup?*/);
	~Encoder();
	string encode(string& input);
private:
	char registers[3];
	int XOR1[2];
	int XOR2[2];
};

