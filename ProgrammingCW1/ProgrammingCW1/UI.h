#pragma once
#include <iostream>

using namespace std;

class UI
{
public:
	UI();
	~UI();
	int menu();
	void generateAll(bool);
	void generateUnique(bool);
	void generateCustom();
	void viewAll(bool);
	void viewUnique(bool);
	void viewCustom(bool);
};

