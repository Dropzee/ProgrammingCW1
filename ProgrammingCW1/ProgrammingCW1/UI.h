#pragma once
#include "Encoder.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class UI
{
public:
	UI();
	~UI();
	int menu();
	void generateAll(bool);
	void inputCustom(string s, Encoder* e);
	void viewAll(vector<string> names, vector<string> outputs);
};

