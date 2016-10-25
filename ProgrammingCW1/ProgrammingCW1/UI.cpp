#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

int UI::menu() {
	cout << "---------------- MENU ----------------" << endl;
	cout << "1. Generate all permutations" << endl;
	cout << "2. Generate unique permutations only" << endl;
	cout << "3. Input custom permutation" << endl;
	cout << "4. View all permutations" << endl;
	cout << "5. View unique permutations" << endl;
	cout << "6. View custom permutations" << endl;
	cout << "7. Exit" << endl;
	cout << "Please choose an option: " << endl;
	int x;
	cin >> x;
	return x;
}

void UI::generateAll(bool b) {
	cout << "--------------------------------------" << endl;
	if (b) {
		cout << "All combinations from 0000 to 3333 in base 4 have been created." << endl;
	}
	else {
		cout << "All combinations have already been created." << endl;
	}
	return;
}

void UI::generateUnique(bool b) {}
void UI::generateCustom() {}
void UI::viewAll(bool b) {}
void UI::viewUnique(bool b) {}
void UI::viewCustom(bool b) {}