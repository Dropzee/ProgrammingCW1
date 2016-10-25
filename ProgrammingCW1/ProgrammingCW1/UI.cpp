#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

int UI::menu() throw (invalid_argument) {
	cout << "---------------- MENU ----------------" << endl;
	cout << "1. Generate all unique permutations only" << endl;
	cout << "2. Input custom permutation" << endl;
	cout << "3. View all permutations" << endl;
	cout << "4. View custom permutations" << endl;
	cout << "5. Exit" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Please choose an option: ";
	int x;
	if (!(cin >> x)) {
		throw invalid_argument("Invalid input.");
	}
	return x;
}

void UI::generateAll(bool b) {
	cout << "--------------------------------------" << endl;
	if (b) {
		cout << "All unique outputs using combinations from 0000 to 3333 in base 4 have been created." << endl;
	}
	else {
		cout << "All unique combinations have already been created." << endl;
	}
	return;
}

void UI::inputCustom() {}

void UI::viewAll(vector<string> names, vector<string> outputs) throw (invalid_argument) {
	cout << "--------------------------------------" << endl;
	if (outputs.empty()) {
		cout << "No outputs generated, please generate first." << endl;
	}
	else {
		int count = 0;
		for each(string s in names) {
			cout << count << ". " << s.c_str() << endl;
			count++;
		}
		cout << "--------------------------------------" << endl;
		cout << "Input an index from the list above to view encoded output: ";
		int x;
		if (!(cin >> x)) {
			throw invalid_argument("Invalid input.");
		}
		cout << "--------------------------------------" << endl;
		cout << outputs.at(x).c_str() << endl;
	}
	return;
}
