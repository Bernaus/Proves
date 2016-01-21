#include "Data.hpp"
#include "conio.h"
#include "iostream"

using namespace std;

int main() {
	Data *d1;
	try {
		d1 = new Data(32, 1, 2014);
	} catch (char const* str) {
		cout << "Error: " << str << "\n";
	}
	try {
		d1 = new Data(10, 13, 2014);
	} catch (char const* str) {
		cout << "Error: " << str << "\n";
	}
	try {
		d1 = new Data(10, 10, -2014);
	} catch (char const* str) {
		cout << "Error: " << str << "\n";
	}
	try {
		d1 = new Data(29, 2, 2013);
	} catch (char const* str) {
		cout << "Error: " << str << "\n";
	}
	try {
		d1 = new Data(29, 2, 2012);
	} catch (char const* str) {
		cout << "Error: " << str << "\n";
	}
	cout << "*d1: " << *d1 << endl;
	Data d2 = *d1+10000;
	cout << "d2: " << d2 << endl;
	Data d3 = d2-10000;
	cout << "d3: " << d3 << endl;
	cout << "d2-d1: " << d2-*d1 << endl;
	cout << "*d1<d2?: " << (d1->dataCmp(&d2) == -1 ? true : false) << endl;
	cout << "*d1>d2?: " << (d1->dataCmp(&d2) == 1 ? true : false) << endl;
	cout << "*d1==d3?: " << (d1->dataCmp(&d3) == 0 ? true : false)<< endl;

	getch();
}
