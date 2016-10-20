#pragma once
#include <iostream>

using namespace std;

class Encoder
{
public:
	Encoder();
	//Encoder(/*register setup?*/);
	~Encoder();
	string encode(string input);
private:
	char XOR(char a, char b);
};

